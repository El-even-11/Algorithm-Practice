package main

import (
	"fmt"
	"sort"
)

type Tree struct {
	height int
	i, j   int
}

type ByHeight []Tree

func (a ByHeight) Len() int           { return len(a) }
func (a ByHeight) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByHeight) Less(i, j int) bool { return a[i].height < a[j].height }

func cutOffTree(forest [][]int) int {
	m := len(forest)
	n := len(forest[0])
	trees := make(ByHeight, 0, m*n)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if forest[i][j] > 1 {
				trees = append(trees,
					Tree{
						height: forest[i][j],
						i:      i,
						j:      j,
					},
				)
			}
		}
	}

	sort.Sort(trees)

	dirs := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	x, y := 0, 0
	res := 0

	for _, tree := range trees {
		if x == tree.i && y == tree.j {
			continue
		}
		queue := make([][]int, 1, m*n)
		queue[0] = []int{x, y}
		step := 1
		vis := [50][50]bool{}
		found := false
		vis[x][y] = true
	loop:
		for len(queue) > 0 {
			l := len(queue)
			for k := 0; k < l; k++ {
				pos := queue[k]
				for _, dir := range dirs {
					i := pos[0] + dir[0]
					j := pos[1] + dir[1]
					if i < 0 || j < 0 || i >= m || j >= n {
						continue
					}
					if forest[i][j] == 0 || vis[i][j] {
						continue
					}
					if i == tree.i && j == tree.j {
						found = true
						res += step
						break loop
					}
					vis[i][j] = true
					queue = append(queue, []int{i, j})
				}
			}
			queue = queue[l:]
			step++
		}
		if !found {
			return -1
		}
		x = tree.i
		y = tree.j
	}

	return res
}

func main() {
	fmt.Println(cutOffTree([][]int{{1,2,3},{0,0,4},{7,6,5}}))
}
