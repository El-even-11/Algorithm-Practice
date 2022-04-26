package main

func projectionArea(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	sum := m * n

	for i := 0; i < m; i++ {
		max1 := 0
		max2 := 0
		for j := 0; j < n; j++ {
			if grid[i][j] > 0 {
                sum++
            }
			if grid[i][j] > max1 {
				max1 = grid[i][j]
			}
			if grid[j][i] > max2 {
				max2 = grid[j][i]
			}
		}
		sum += (max1 + max2)
	}

	return sum
}
