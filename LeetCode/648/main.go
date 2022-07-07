package main

import "strings"

type Node struct {
	end  bool
	next []*Node
}

type Tree struct {
	root *Node
}

func (tree *Tree) add(word string) {
	node := tree.root
	for i := 0; i < len(word); i++ {
		if node.next[word[i]-'a'] == nil {
			node.next[word[i]-'a'] = new(Node)
			node.next[word[i]-'a'].next = make([]*Node, 26)
		}
		node = node.next[word[i]-'a']
	}
	node.end = true
}

func (tree *Tree) search(word string) string {
	node := tree.root
	for i := 0; i < len(word); i++ {
		if node.next[word[i]-'a'] == nil {
			return word
		}
		if node.next[word[i]-'a'].end {
			return word[:i+1]
		}
		node = node.next[word[i]-'a']
	}
	return word
}

func replaceWords(dictionary []string, sentence string) string {
	tree := Tree{root: new(Node)}
	tree.root.next = make([]*Node, 26)
	for _, root := range dictionary {
		tree.add(root)
	}
	words := strings.Split(sentence, " ")
	builder := strings.Builder{}
	for i := 0; i < len(words); i++ {
		words[i] = tree.search(words[i])
		builder.WriteString(words[i] + " ")
	}
	return strings.TrimSpace(builder.String())
}
