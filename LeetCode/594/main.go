package main

import "sort"

func findLHS(nums []int) int {
	m := make(map[int]int)
	for _, a := range nums {
		m[a]++
	}
	sort.Ints(nums)
	ret := 0
	for i := 0; i < len(nums)-1; i++ {
		if nums[i+1]-nums[i] == 1 {
			ret = max(ret, m[nums[i]]+m[nums[i+1]])
		}
	}
	return ret
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
