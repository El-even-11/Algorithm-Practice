package main

type Node struct {
	Val         bool
	IsLeaf      bool
	TopLeft     *Node
	TopRight    *Node
	BottomLeft  *Node
	BottomRight *Node
}

func same(grid [][]int) bool {
	n := len(grid)
	a := grid[0][0]
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] != a {
				return false
			}
		}
	}

	return true
}

func cut(grid [][]int, start1, end1, start2, end2 int) [][]int {
	res := make([][]int, end1-start1)

	for i := 0; i < end1-start1; i++ {
		res[i] = make([]int, end1-start1)
	}

	for i := start1; i < end1; i++ {
		for j := start2; j < end2; j++ {
			res[i-start1][j-start2] = grid[i][j]
		}
	}

	return res
}

func construct(grid [][]int) *Node {
	n := len(grid)

	if n == 1 {
		return &Node{
			Val:    grid[0][0] == 1,
			IsLeaf: true,
		}
	}

	if same(grid) {
		return &Node{
			Val:    grid[0][0] == 1,
			IsLeaf: true,
		}
	}

	return &Node{
		IsLeaf:      false,
		TopLeft:     construct(cut(grid, 0, n/2, 0, n/2)),
		TopRight:    construct(cut(grid, 0, n/2, n/2, n)),
		BottomLeft:  construct(cut(grid, n/2, n, 0, n/2)),
		BottomRight: construct(cut(grid, n/2, n, n/2, n)),
	}
}
