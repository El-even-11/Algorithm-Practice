package main

import "unicode"

func detectCapitalUse(word string) bool {

	cnt := 0
	for _, r := range word {
		if unicode.IsUpper(r) {
			cnt++
		}
	}
	return cnt == 0 || unicode.IsUpper(rune(word[0])) && cnt == 1 || cnt == len(word)
}
