package main

import "sort"

func wiggleSort(nums []int) {
	n := len(nums)
	if n == 1 {
		return
	}
	tmp := make([]int, n)

	for i := 0; i < n; i++ {
		tmp[i] = nums[i]
	}

	sort.Ints(tmp)

	mid := 0
	if n%2 == 0 {
		mid = (tmp[n/2-1] + tmp[n/2]) / 2
		
	} else {
		mid = tmp[n/2]
	}

	l := 0
	h := 1

	for i := 0; i < n; i++ {
		if tmp[i] <= mid {
			nums[l] = tmp[i]
			l += 2
		} else {
			nums[h] = tmp[i]
			h += 2
		}
	}
}
