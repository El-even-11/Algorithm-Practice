package main

func isAlienSorted(words []string, order string) bool {
	m := make(map[byte]int)
	for i := 0; i < len(order); i++ {
		m[order[i]] = i
	}

	max := 0

	for i := 0; i < len(words); i++ {
		if len(words[i]) > max {
			max = len(words[i])
		}
	}

	for j := 0; j < max; j++ {

		for len(words) > 1 && len(words[0]) <= j {
			words = words[1:]
		}

		pre := m[words[0][j]]
		i := 1
		for i < len(words) {
			if len(words[i]) <= j {
				return false
			}

			if m[words[i][j]] < pre {
				return false
			}
			if m[words[i][j]] > pre {
				pre = m[words[i][j]]
				words = append(words[0:i], words[i+1:]...)
				continue
			}
			i++
		}
		if len(words) == 1 {
			return true
		}
	}

	return true
}
