package main

type word struct {
	s string
	c map[rune]bool
}

func mulLen(w1, w2 word) int {
	for _, ch := range "abcdefghijklmnopqrstuvwxyz" {
		if w1.c[ch] && w2.c[ch] {
			return 0
		}
	}
	return len(w1.s) * len(w2.s)
}

func maxProduct(ws []string) int {

	var words []word
	for _, w := range ws {
		c := make(map[rune]bool)
		for _, r := range w {
			c[r] = true
		}
		words = append(words, word{s: w, c: c})
	}

	n := len(ws)
	max := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			l := mulLen(words[i], words[j])
			if l > max {
				max = l
			}
		}
	}

	return max
}
