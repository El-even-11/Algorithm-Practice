package main

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxCount(m int, n int, ops [][]int) int {
	amin := ops[0][0]
	bmin := ops[0][1]

	for i := 1; i < len(ops); i++ {
		amin = min(amin, ops[i][0])
		bmin = min(bmin, ops[i][1])
	}

	return amin * bmin
}
