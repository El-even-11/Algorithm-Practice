// fail

package main

var dir [][]int

type N struct {
	i, j, t int
	p       bool
}

var m, n int

var q []N

var g [][]int

func bfs() int {
	for len(q) > 0 {
		x := q[0]
		q = q[1:]
		if x.p && x.i == m-1 && x.j == n-1 {
			return x.t
		}

		for _, d := range dir {
			di := x.i + d[0]
			dj := x.j + d[1]
			if di >= 0 && di < m && dj >= 0 && dj < n && g[di][dj] == 0 || (!x.p && g[di][dj] == 3) {
				if g[di][dj] == 0 {
					g[di][dj] = 1
				}
				q = append(q, N{di, dj, x.t + 1, x.p})
			}
		}
	}

	return -1
}

func maximumMinutes(grid [][]int) int {
	g = grid
	m, n = len(grid), len(grid[0])
	g[0][0] = 3

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if g[i][j] == 1{

			}
		}
	}

	dir = [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	q = make([]N, 0)

	t := 0

}
