package main

type Node struct {
	Val      int
	Children []*Node
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	m := 1
	for _, node := range root.Children {
		m = max(m, maxDepth(node)+1)
	}
	return m
}
