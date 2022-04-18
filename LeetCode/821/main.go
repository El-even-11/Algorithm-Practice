package main

func shortestToChar(s string, c byte) []int {
	n := len(s)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = -1
	}

	cs := []int{}

	for i := 0; i < n; i++ {
		if s[i] == c {
			cs = append(cs, i)
			res[i] = 0
		}
	}

	dis := 1

	for {
		updated := false
		for _, i := range cs {
			if i+dis < n && res[i+dis] == -1 {
				res[i+dis] = dis
				updated = true
			}
			if i-dis >= 0 && res[i-dis] == -1 {
				res[i-dis] = dis
				updated = true
			}
		}
		if !updated {
			break
		}
		dis++
	}

	return res
}
