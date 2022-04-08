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
	i := 0
	cnt := 1
	for len(queue) > 0 {
		ret = append(ret, []int{})
		now := 0
		for j := 0; j < cnt; j++ {
			node := queue[0]
			queue = queue[1:]
			ret[i] = append(ret[i], node.Val)
			for _, child := range node.Children {
				if child != nil {
					now++
					queue = append(queue, child)
				}
			}
		}
		cnt = now
		i++
	}

	return ret
}
