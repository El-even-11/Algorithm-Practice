package main

import "fmt"

var reachable1, reachable2, r [][]bool
var heights [][]int
var dir [][]int
var m, n int

func pacificAtlantic(_heights [][]int) [][]int {
	heights = _heights
	m = len(heights)
	n = len(heights[0])
	dir = [][]int{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}
	reachable1 = make([][]bool, m)
	reachable2 = make([][]bool, m)
	r = make([][]bool, m)
	for i := 0; i < m; i++ {
		reachable1[i] = make([]bool, n)
		reachable2[i] = make([]bool, n)
		r[i] = make([]bool, n)
	}

	res := [][]int{}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if dfs1(i, j, r) && dfs2(i, j, r) {
				res = append(res, []int{i, j})
			}
		}
	}

	return res
}

func dfs1(i, j int, r [][]bool) bool {
	if reachable1[i][j] {
		return true
	}

	r[i][j] = true

	for _, d := range dir {
		di := i + d[0]
		dj := j + d[1]
		if di < 0 || dj < 0 {
			reachable1[i][j] = true
			r[i][j] = false
			return true
		}
		if di >= m || dj >= n {
			reachable2[i][j] = true
			continue
		}
		if r[di][dj] {
			continue
		}
		if heights[di][dj] > heights[i][j] {
			continue
		}
		if dfs1(di, dj, r) {
			reachable1[i][j] = true
			r[i][j] = false
			return true
		}
	}
	r[i][j] = false
	return false
}

func dfs2(i, j int, r [][]bool) bool {
	if reachable2[i][j] {
		return true
	}

	r[i][j] = true

	for _, d := range dir {
		di := i + d[0]
		dj := j + d[1]
		if di >= m || dj >= n {
			reachable2[i][j] = true
			r[i][j] = false
			return true
		}
		if di < 0 || dj < 0 {
			reachable1[i][j] = true
			continue
		}
		if r[di][dj] {
			continue
		}
		if heights[di][dj] > heights[i][j] {
			continue
		}
		if dfs2(di, dj, r) {
			reachable2[i][j] = true
			r[i][j] = false
			return true
		}
	}
	r[i][j] = false
	return false
}

func main() {
	h := [][]int{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}}
	res := pacificAtlantic(h)
	fmt.Println(res)
}
