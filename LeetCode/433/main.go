package main

func findNext(now string, bank []string, used map[string]struct{}) []string {
	next := make([]string, 0)
	for _, word := range bank {
		if _, ok := used[word]; ok {
			continue
		}
		cnt := 0
		for i := 0; i < 8; i++ {
			if word[i] != now[i] {
				cnt++
			}
		}
		if cnt == 1 {
			next = append(next, word)
		}
	}
	return next
}

func minMutation(start string, end string, bank []string) int {

	if start == end {
		return 0
	}
	used := make(map[string]struct{})
	next := findNext(start, bank, used)
	depth := 1

	for len(next) > 0 {
		for _, word := range next {
			if word == end {
				return depth
			}
			used[word] = struct{}{}
		}

		a := len(next)

		for i := 0; i < a; i++ {
			next = append(next, findNext(next[i], bank, used)...)
		}

		next = next[a:]
		depth++
	}

	return -1
}
