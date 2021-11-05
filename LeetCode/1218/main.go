package main

import "fmt"

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestSubsequence(arr []int, difference int) int {
	var f [][]int
	n := len(arr)
	for i := 0; i < n; i++ {
		arr := make([]int, 2)
		f = append(f, arr)
	}

	m := make(map[int]int)
	f[0][0] = 0
	f[0][1] = 1
	m[arr[0]] = 0
	for i := 1; i < n; i++ {
		m[arr[i]] = i
		f[i][0] = max(f[i-1][0], f[i-1][1])
		if _, ok := m[arr[i]-difference]; !ok {
			f[i][1] = 1
			continue
		}
		f[i][1] = f[m[arr[i]-difference]][1] + 1
	}

	return max(f[n-1][0], f[n-1][1])
}

func main() {
	arr := []int{1, 2, 3, 4}
	fmt.Printf("result: %d", longestSubsequence(arr, 1))
}
