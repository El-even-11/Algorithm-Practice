package main

func buddyStrings(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}
	cnt := 0

	var idx []int
	m := make(map[byte]int)

	for i := 0; i < len(s); i++ {
		m[s[i]]++
		if s[i] != goal[i] {
			idx = append(idx, i)
			cnt++
		}
		if cnt > 2 {
			return false
		}
	}

	if cnt == 1 {
		return false
	}

	if cnt == 2 {
		if s[idx[0]] == goal[idx[1]] && s[idx[1]] == goal[idx[0]] {
			return true
		}
		return false
	}

	for _, v := range m {
		if v >= 2 {
			return true
		}
	}

	return false
}
