package main

func ladderLength(beginWord string, endWord string, wordList []string) int {
	if beginWord == endWord {
		return 1
	}
	set := make(map[string]struct{})
	for _, word := range wordList {
		set[word] = struct{}{}
	}

	if _, ok := set[endWord]; !ok {
		return 0
	}

	q1 := make([]string, 0)
	q1 = append(q1, beginWord)

	q2 := make([]string, 0)
	q2 = append(q2, endWord)

	m1 := make(map[string]int)
	m2 := make(map[string]int)

	m1[beginWord] = 0
	m2[endWord] = 0

	res := 0

	update := func(q *[]string, cur map[string]int, other map[string]int) {
		m := len(*q)
		for i := 0; i < m; i++ {
			s := (*q)[i]
			for j := 0; j < len(s); j++ {
				for _, ch := range "abcdefghijklmnopqrstuvwxyz" {
					t := []byte(s)
					t[j] = byte(ch)
					sub := string(t)
					if _, ok := set[sub]; ok {
						if _, ok := cur[sub]; ok && cur[sub] <= cur[s] +1{
							continue
						}
						if _, ok := other[sub]; ok {
							res = cur[s] + other[sub] + 1
							return
						}
						*q = append(*q, sub)
						cur[sub] = cur[s] + 1
					}
				}
			}
		}
		*q = (*q)[m:]
	}

	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) < len(q2) {
			update(&q1, m1, m2)
		} else {
			update(&q2, m2, m1)
		}

		if res > 0 {
			return res + 1
		}
	}

	return 0
}
