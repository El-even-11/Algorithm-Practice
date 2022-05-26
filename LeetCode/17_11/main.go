package main

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func findClosest(words []string, word1 string, word2 string) int {
	a := make([]int, 0)
	b := make([]int, 0)
	for i, word := range words {
		if word == word1 {
			a = append(a, i)
		}
		if word == word2 {
			b = append(b, i)
		}
	}

	min := 0x7fffffff
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			t := abs(a[i] - b[j])
			if t < min {
				min = t
			}
		}
	}

	return min
}
