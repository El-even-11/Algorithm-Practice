package main

import (
	"sort"
)

func minMoves2(nums []int) int {
	sort.Ints(nums)
	var mid int
	if len(nums)%2 == 0 {
		mid = (nums[len(nums)/2-1] + nums[len(nums)/2]) / 2
	} else {
		mid = nums[len(nums)/2]
	}

	res := 0

	for _, a := range nums {
		if a < mid {
			res += mid - a
		} else {
			res += a - mid
		}
	}

	return res
}
