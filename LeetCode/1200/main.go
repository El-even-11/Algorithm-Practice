package main

import "sort"

func minimumAbsDifference(arr []int) [][]int {
	sort.Ints(arr)
	res := [][]int{}
	min := 0x7fffffff
	for i := 0; i+1 < len(arr); i++ {
		if arr[i+1]-arr[i] < min {
			min = arr[i+1] - arr[i]
			res = [][]int{{arr[i], arr[i+1]}}
		} else if arr[i+1]-arr[i] == min {
			res = append(res, []int{arr[i], arr[i+1]})
		}
	}

	return res
}
