package main

func smallestRangeI(nums []int, k int) int {
	max := -1
	min := 10001

	for _, k := range nums {
		if max < k {
			max = k
		}
		if min > k {
			min = k
		}
	}

	max -= k
	min += k
	if min >= max {
		return 0
	}
	return max - min
}
