package main

func uniqueMorseRepresentations(words []string) int {

	p := []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}

	m := make(map[string]int)
	for _, word := range words {
		s := ""
		for _, ch := range word {
			s += p[ch-'a']
		}
		m[s]++
	}

	return len(m)
}
