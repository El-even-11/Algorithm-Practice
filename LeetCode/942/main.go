package main

func diStringMatch(s string) []int {
	res := make([]int, len(s)+1)
	l := 0
	r := len(s)

	for i, ch := range s {
		if ch == 'I' {
			res[i] = l
			l++
		} else {
			res[i] = r
			r--
		}
	}

	res[len(s)] = l

	return res
}
