package main

type Node struct {
	Val      int
	Children []*Node
}

func levelOrder(root *Node) [][]int {
	if root == nil {
		return nil
	}
	queue := []*Node{root}

	ret := [][]int{}
	for len(queue) > 0 {
		row := []int{}
		size := len(queue)
		for j := 0; j < size; j++ {
			node := queue[0]
			queue = queue[1:]
			row = append(row, node.Val)
			for _, child := range node.Children {
				if child != nil {
					queue = append(queue, child)
				}
			}
		}
		ret = append(ret, row)
	}

	return ret
}
