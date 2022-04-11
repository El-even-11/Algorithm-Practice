package main

func countNumbersWithUniqueDigits(n int) int {
	if n == 0 {
		return 1
	}

	m := []int{
		0,
		10,
		9 * 9,
		9 * 9 * 8,
		9 * 9 * 8 * 7,
		9 * 9 * 8 * 7 * 6,
		9 * 9 * 8 * 7 * 6 * 5,
		9 * 9 * 8 * 7 * 6 * 5 * 4,
		9 * 9 * 8 * 7 * 6 * 5 * 4 * 3,
	}

	ret := 0
	for i := 0; i <= n; i++ {
		ret += m[i]
	}
	return ret
}
