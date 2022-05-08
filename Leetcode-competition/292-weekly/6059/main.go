// time limit exceed

package main

var grid [][]byte
var m, n int

var exist [101][101][300]bool

func dfs(i, j int, q int) bool {

	if q > m+n-i-j-1 {
		return false
	}

	if i == m-1 && j == n-1 {

		return q == 1
	}

	if exist[i][j][q] {
		return false
	}

	exist[i][j][q] = true

	if grid[i][j] == '(' {
		q++
	} else {
		q--
		if q < 0 {
			return false
		}
	}

	return i < m-1 && dfs(i+1, j, q) || j < n-1 && dfs(i, j+1, q)
}

func hasValidPath(_grid [][]byte) bool {
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < m+n; k++ {
				exist[m][n][k] = false
			}
		}
	}

	grid = _grid
	m = len(grid)
	n = len(grid[0])
	if (m+n)%2 == 0 || grid[0][0] == ')' || grid[m-1][n-1] == '(' {
		return false
	}
	return dfs(0, 0, 0)
}
