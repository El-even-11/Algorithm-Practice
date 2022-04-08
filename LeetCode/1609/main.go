package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isEvenOddTree(root *TreeNode) bool {

	queue := []*TreeNode{root}

	i := 0
	for len(queue) > 0 {
		size := len(queue)
		pre := (i % 2) * 0x7fffffff

		for j := 0; j < size; j++ {
			node := queue[0]
			queue = queue[1:]
			if node.Val%2 == i%2 {
				return false
			}
			if i%2 == 0 && node.Val <= pre || i%2 == 1 && node.Val >= pre {
				return false
			}
			pre = node.Val

			if node.Left != nil {
				queue = append(queue, node.Left)
			}

			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		i++
	}

	return true
}

func main() {
	root := TreeNode{
		Val: 5,
		Left: &TreeNode{
			Val: 4,
			Left: &TreeNode{
				Val: 3,
			},
			Right: &TreeNode{
				Val: 3,
			},
		},
		Right: &TreeNode{
			Val: 2,
			Left: &TreeNode{
				Val: 7,
			},
		},
	}

	isEvenOddTree(&root)
}
