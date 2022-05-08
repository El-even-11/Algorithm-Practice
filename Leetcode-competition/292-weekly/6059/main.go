// time limit exceed

package main

var grid [][]byte
var m, n int

var exist [101][101][300]int

func dfs(i, j int, q int) bool {
	if exist[i][j][q] > 0 {
		return exist[i][j][q] == 2
	}

	if q == 0 {
		if grid[i][j] == ')' {
			exist[i][j][q] = 1
			return false
		} else {
			q++
		}
	} else {

		if grid[i][j] == ')' {
			q--
		} else {
			q++
		}

		if q > (m+n)/2 {
			exist[i][j][q] = 1
			return false
		}
	}

	if i == m-1 && j == n-1 {
		if q == 0 {
			exist[i][j][q] = 2
		} else {
			exist[i][j][q] = 1
		}

		return q == 0
	}

	l := false
	r := false
	if i == m-1 {
		l = dfs(i, j+1, q)
	} else if j == n-1 {
		r = dfs(i+1, j, q)
	} else {
		l = dfs(i, j+1, q)
		if l {
			exist[i][j][q] = 2
			return true	
		}

		r = dfs(i+1, j, q)
		if r {
			exist[i][j][q] = 2
			return true	
		}
	}

	if l || r {
		exist[i][j][q] = 2
	} else {
		exist[i][j][q] = 1
	}
	return l || r
}

func hasValidPath(_grid [][]byte) bool {
	grid = _grid
	m = len(grid)
	n = len(grid[0])
	if (m+n)%2 == 0 {
		return false
	}
	return dfs(0, 0, 0)
}
