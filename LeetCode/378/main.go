package main

func kthSmallest(matrix [][]int, k int) int {
	m := len(matrix)
	n := len(matrix[0])

	l := matrix[0][0]
	r := matrix[m-1][n-1]

	getCnt := func(x int) int {
		cnt := 0

		for i := 0; i < m && matrix[i][0] <= x; i++ {
			l := 0
			r := n - 1
			if matrix[i][r] <= x {
				cnt += n
				continue
			}

			for l < r {
				mid := (l + r) >> 1
				if matrix[i][mid] > x {
					r = mid
				} else {
					l = mid + 1
				}
			}

			cnt += r
		}

		return cnt
	}

	for l < r {
		mid := (l + r) >> 1
		cnt := getCnt(mid)
		if cnt >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}

	return r
}

func main() {
	m := [][]int{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}
	kthSmallest(m, 8)
}
