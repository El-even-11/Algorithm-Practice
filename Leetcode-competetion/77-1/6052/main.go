package main

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func minimumAverageDifference(nums []int) int {
	sum := make([]int, len(nums)+1)

	sum[0] = 0
	for i := 1; i <= len(nums); i++ {
		sum[i] = sum[i-1] + nums[i-1]
	}

	min := 10000000
	ret := 0
	for i := 0; i < len(nums); i++ {
		arr1 := sum[i+1] / (i + 1)
		arr2 := (sum[len(nums)] - sum[i+1]) / max(len(nums)-i-1, 1)
		a := max(arr1-arr2, arr2-arr1)
		if a < min {
			min = a
			ret = i
		}
	}

	return ret
}

func main() {
	nums := []int{2, 5, 3, 9, 5, 3}
	minimumAverageDifference(nums)
}
