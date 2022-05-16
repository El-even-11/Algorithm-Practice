package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	max := 0x7fffffff
	var maxNode *TreeNode

	var search func(node *TreeNode)
	search = func(node *TreeNode) {
		if node == nil {
			return
		}

		if node.Val <= p.Val {
			search(node.Right)
			return
		}

		if node.Val >= max {
			return
		}

		max = node.Val
		maxNode = node
		search(node.Left)
	}

	search(root)

	return maxNode
}
