package main

import "strings"

func countPrefixes(words []string, s string) int {
	cnt := 0
	for _, word := range words {
		if strings.HasPrefix(s, word) {
			cnt++
		}
	}

	return cnt
}
