package main

func maxArea(height []int) int {
	max := 0
	i := 0
	j := len(height) - 1
	for i < j {
		var t int
		if height[i] < height[j] {
			t = (j - i) * height[i]
			i++
		} else {
			t = (j - i) * height[j]
			j--
		}
		if max < t {
			max = t
		}
	}

	return max
}
