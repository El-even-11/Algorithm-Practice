package main

func numSubarrayProductLessThanK(nums []int, k int) int {
	i, j := 0, 0
	cnt := 0
	mul := 1
	if k <= 1 {
		return 0
	}
	for j < len(nums) {
		mul *= nums[j]
		for mul >= k {
			mul /= nums[i]
			i++
		}
		cnt += (j - i + 1)
		j++
	}

	return cnt
}
