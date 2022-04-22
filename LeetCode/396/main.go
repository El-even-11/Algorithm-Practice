package main

func maxRotateFunction(nums []int) int {

	n := len(nums)
	sum := 0
	max := 0
	for i, a := range nums {
		sum += a
		max += i * a
	}

	nums = append(nums, nums...)

	pre := max
	for i := 1; i < n; i++ {
		t := pre - sum + n*nums[i+n-1]
		if t > max {
			max = t
		}
		pre = t
	}

	return max
}
