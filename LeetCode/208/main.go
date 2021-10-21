package main

type Trie struct {
	tns [26]*Trie
	end bool
}

func Constructor() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	p := this
	n := len(word)
	for i := 0; i < n; i++ {
		ch := word[i] - 'a'
		if p.tns[ch] == nil {
			p.tns[ch] = new(Trie)
		}
		p = p.tns[ch]
	}
	p.end = true
}

func (this *Trie) Search(word string) bool {
	p := this
	n := len(word)
	for i := 0; i < n; i++ {
		ch := word[i] - 'a'
		if p.tns[ch] == nil {
			return false
		}
		p = p.tns[ch]
	}
	return p.end
}

func (this *Trie) StartsWith(prefix string) bool {
	p := this
	n := len(prefix)
	for i := 0; i < n; i++ {
		ch := prefix[i] - 'a'
		if p.tns[ch] == nil {
			return false
		}
		p = p.tns[ch]
	}
	return true
}

func main() {

}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
