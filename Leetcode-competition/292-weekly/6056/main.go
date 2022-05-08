package main

import "strconv"

func largestGoodInteger(num string) string {

	res := ""
	max := 0
	for i := 0; i+2 < len(num); i++ {
		if num[i] == num[i+1] && num[i] == num[i+2] {
			a, _ := strconv.Atoi(num[i:i+3])
			if a >= max {
				res = num[i:i+3]
				max = a
			}
		}
	}

	return res
}
