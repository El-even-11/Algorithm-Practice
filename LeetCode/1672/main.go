package main

func maximumWealth(accounts [][]int) int {
	max := -1
	for _, account := range accounts {
		t := 0
		for _, num := range account {
			t += num
		}
		if t > max {
			max = t
		}
	}

	return max
}
