package main

import "sort"

func findRightInterval(intervals [][]int) []int {
	n := len(intervals)
	left := make([]int, n)
	right := make([]int, n)
	idx := make(map[int]int)
	for i := 0; i < n; i++ {
		left[i] = intervals[i][0]
		right[i] = intervals[i][1]
		idx[left[i]] = i
	}

	sort.Ints(left)

	res := make([]int, n)
	cache := make(map[int]int)

	for i := 0; i < n; i++ {
		if _, ok := cache[right[i]]; ok {
			res[i] = cache[right[i]]
			continue
		}
		l := 0
		r := n - 1
		for l < r {
			mid := (l + r) >> 1
			if left[mid] >= right[i] {
				r = mid
			} else {
				l = mid + 1
			}
		}

		if left[r] < right[i] {
			res[i] = -1
			cache[right[i]] = -1
			continue
		}
		res[i] = idx[left[r]]
		cache[right[i]] = idx[left[r]]
	}

	return res
}

func main() {
	findRightInterval([][]int{{3, 4}, {2, 3}, {1, 2}})
}
