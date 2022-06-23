package main

func findSubstring(s string, words []string) []int {
	m := make(map[string]int)
	cp := make(map[string]int)
	l := len(words[0])
	for _, word := range words {
		m[word]++
		cp[word]++
	}

	i := 0
	j := l
	res := make([]int, 0)
	for i < len(s) && j <= len(s) {
		if m[s[j-l:j]] == 0 {
			i++
			j = i + l
			for k, v := range cp {
				m[k] = v
			}
			continue
		}

		if (j-i)/l == len(words) {
			res = append(res, i)
			i++
			j = i + l
			for k, v := range cp {
				m[k] = v
			}
			continue
		}

		m[s[j-l:j]]--
		j += l
	}

	return res
}

func main() {
	s := "barfoofoobarthefoobarman"
	words := []string{"bar", "foo", "the"}
	findSubstring(s, words)
}
