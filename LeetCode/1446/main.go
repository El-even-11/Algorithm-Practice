package main

func maxPower(s string) int {
	b := s[0]

	cnt := 1
	max := 1
	for i := 1; i < len(s); i++ {
		if s[i] == b {
			cnt++
		} else {
			b = s[i]
			if cnt > max {
				max = cnt
			}
			cnt = 1
		}
	}

	if cnt > max {
		max = cnt
	}
	return max
}
