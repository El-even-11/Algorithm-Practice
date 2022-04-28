package main

type Node struct {
	Val         bool
	IsLeaf      bool
	TopLeft     *Node
	TopRight    *Node
	BottomLeft  *Node
	BottomRight *Node
}

func same(grid [][]int, a, b, c, d int) bool {
	x := grid[a][c]
	for i := a; i < b; i++ {
		for j := c; j < d; j++ {
			if grid[i][j] != x {
				return false
			}
		}
	}

	return true
}

func construct(grid [][]int) *Node {
	return cons(grid, 0, len(grid), 0, len(grid))
}

func cons(grid [][]int, a, b, c, d int) *Node {
	n := b - a

	if n == 1 {
		return &Node{
			Val:    grid[a][c] == 1,
			IsLeaf: true,
		}
	}

	if same(grid, a, b, c, d) {
		return &Node{
			Val:    grid[a][c] == 1,
			IsLeaf: true,
		}
	}

	return &Node{
		IsLeaf:      false,
		TopLeft:     cons(grid, a, (a+b)/2, c, (c+d)/2),
		TopRight:    cons(grid, a, (a+b)/2, (c+d)/2, d),
		BottomLeft:  cons(grid, (a+b)/2, b, c, (c+d)/2),
		BottomRight: cons(grid, (a+b)/2, b, (c+d)/2, d),
	}
}
