package main

import "fmt"

func getHint(secret string, guess string) string {
	var A int
	var B int

	n := len(secret)
	used := make([]bool, n)
	for i := 0; i < n; i++ {
		if secret[i] == guess[i] {
			A++
			used[i] = true
		}
	}

	m := make(map[byte]int)
	for i := 0; i < n; i++ {
		if !used[i] {
			m[secret[i]]++
		}
	}

	for i := 0; i < n; i++ {
		if !used[i] && m[guess[i]] > 0 {
			B++
			m[guess[i]]--
		}
	}

	return fmt.Sprintf("%dA%dB", A, B)
}
