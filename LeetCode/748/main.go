package main

func shortestCompletingWord(licensePlate string, words []string) string {
	m := make(map[byte]int)

	for i := 0; i < len(licensePlate); i++ {
		if licensePlate[i] >= 'a' && licensePlate[i] <= 'z' {
			m[licensePlate[i]]++
		}
		if licensePlate[i] >= 'A' && licensePlate[i] <= 'Z' {
			m[licensePlate[i]-'A'+'a']++
		}
	}

	maxLen := 1000000
	var ret string

	for _, word := range words {
		if len(word) >= maxLen{
			continue
		}
		tmp := make(map[byte]int)
		for k, v := range m {
			tmp[k] = v
		}

		for i := 0; i < len(word); i++ {
			tmp[word[i]]--
		}

		ok := true
		for k := range m {
			if tmp[k] > 0 {
				ok = false
				break
			}
		}
		if ok {
			ret = word
			maxLen = len(word)
		}
	}

	return ret
}

func main(){
	words := []string{"step"}
	shortestCompletingWord("1s3 PSt",words)
}