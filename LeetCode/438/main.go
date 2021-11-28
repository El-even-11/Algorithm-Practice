package main

func findAnagrams(s string, p string) []int {
	m := len(s)
	n := len(p)

	if n > m {
		return []int{}
	}

	cntp := make(map[byte]int)
	cnts := make(map[byte]int)

	chars := "abcdefghijklmnopqrstuvwxyz"

	for i := 0; i < len(chars); i++ {
		cntp[chars[i]] = 0
		cnts[chars[i]] = 0
	}

	for i := 0; i < n; i++ {
		cntp[p[i]]++
	}

	for i := 0; i < n; i++ {
		cnts[s[i]]++
	}

	ret := []int{}

	if equal(cnts, cntp) {
		ret = append(ret, 0)
	}

	for i := 1; i+n <= m; i++ {
		cnts[s[i-1]]--
		cnts[s[i+n-1]]++
		if equal(cnts, cntp) {
			ret = append(ret, i)
		}
	}

	return ret
}

func equal(s, p map[byte]int) bool {
	chars := "abcdefghijklmnopqrstuvwxyz"
	for i := 0; i < len(chars); i++ {
		if s[chars[i]] != p[chars[i]] {
			return false
		}
	}
	return true
}
