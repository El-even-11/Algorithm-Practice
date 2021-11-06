package main

func missingNumber(nums []int) int {
	n := len(nums)
	sum := n * (n + 1) / 2
	ret := func() int {
		var sum int
		for _, k := range nums {
			sum += k
		}
		return sum
	}
	return sum - ret()
}