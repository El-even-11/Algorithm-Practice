package main

import "math"

func findDuplicates(nums []int) []int {
	res := make([]int, 0)
	for _, a := range nums {
		if nums[int(math.Abs(float64(a)))-1] > 0 {
			nums[int(math.Abs(float64(a)))-1] = -nums[int(math.Abs(float64(a)))-1]
		} else {
			res = append(res, int(math.Abs(float64(a))))
		}
	}

	return res
}
