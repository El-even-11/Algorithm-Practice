package main

func findKthNumber(m int, n int, k int) int {
	l := 1
	r := m * n

	getCnt := func(x int) int {
		i := 1
		a := 0
		for i <= x && i <= n {
			if i*m < x {
				a += m
			} else {
				a += x/i
			}
			i++
		}

		return a
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
