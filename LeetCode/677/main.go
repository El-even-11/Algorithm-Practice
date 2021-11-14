package main

type Trie struct {
	tns [26]*Trie
	end bool
	val int
}

type MapSum struct {
	root *Trie
}

func Constructor() MapSum {
	return MapSum{new(Trie)}
}

func (this *MapSum) Insert(key string, val int) {
	p := this.root
	n := len(key)
	for i := 0; i < n; i++ {
		ch := key[i] - 'a'
		if p.tns[ch] == nil {
			p.tns[ch] = new(Trie)
		}
		p = p.tns[ch]
	}
	p.end = true
	p.val = val
}

func (this *MapSum) Sum(prefix string) int {
	p := this.root
	n := len(prefix)
	sum := 0
	for i := 0; i < n; i++ {
		ch := prefix[i] - 'a'
		if p.tns[ch] == nil {
			return 0
		}
		p = p.tns[ch]
	}

	var dfs func(node *Trie)
	dfs = func(node *Trie) {
		if node.end {
			sum += node.val
		}

		for i := 0; i < 26; i++ {
			if node.tns[i] != nil {
				dfs(node.tns[i])
			}
		}
	}
	dfs(p)

	return sum
}

/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
