package main

import "fmt"

func lenLongestFibSubseq(arr []int) int {
	index := make(map[int]int)
	for i, a := range arr {
		index[a] = i
	}

	n := len(arr)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}

	res := 0
	for i := 1; i < n; i++ {
		for j := i + 1; j < n; j++ {
			t := arr[j] - arr[i]
			if _, ok := index[t]; !ok || index[t] > i {
				dp[i][j] = 0
				continue
			}
			dp[i][j] = max(dp[index[t]][i]+1, 3)
			res = max(res, dp[i][j])
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(lenLongestFibSubseq(([]int{2, 4, 7, 8, 9, 10, 14, 15, 18, 23, 32, 50})))
}
