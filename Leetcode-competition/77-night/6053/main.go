package main

var dir [][]int

func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
	dir = [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	mt := make([][]int, m)

	for i := 0; i < m; i++ {
		mt[i] = make([]int, n)
	}

	for _, wall := range walls {
		mt[wall[0]][wall[1]] = 1
	}

	for _, guard := range guards {
		i := guard[0]
		j := guard[1]
		mt[i][j] = 1
		for di := i - 1; di >= 0; di-- {
			if mt[di][j] == 1 || mt[di][j] == -1 {
				break
			}
			mt[di][j] = -1
		}
		for di := i + 1; di < m; di++ {
			if mt[di][j] == 1 || mt[di][j] == -1{
				break
			}
			mt[di][j] = -1
		}
		for dj := j - 1; dj >= 0; dj-- {
			if mt[i][dj] == 1 || mt[i][dj] == -2{
				break
			}
			mt[i][dj] = -2
		}
		for dj := j + 1; dj< n; dj++ {
			if mt[i][dj] == 1 || mt[i][dj] == -2{
				break
			}
			mt[i][dj] = -2
		}
	}

	cnt := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mt[i][j] == 0 {
				cnt++
			}
		}
	}

	return cnt
}
