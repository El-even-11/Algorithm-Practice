package main

func distributeCandies(candyType []int) int {
	m := make(map[int]bool)
	n := len(candyType)

	for _, a := range candyType {
		m[a] = true
	}

	max := len(m)

	if n/2 > max {
		return max
	}

	return n / 2
}
