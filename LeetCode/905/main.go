package main

func sortArrayByParity(nums []int) []int {
	i := 0
	j := len(nums) - 1

	for i < j {
		if nums[i]%2 == 0 {
			i++
		}
		if nums[j]%2 == 1 {
			j--
		}
		if i >= j {
			break
		}
		if nums[i]%2 == 1 && nums[j]%2 == 0 {
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j--
		}
	}

	return nums
}
