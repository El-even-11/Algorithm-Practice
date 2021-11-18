package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ret int

func dfs(root *TreeNode) int {
	if root == nil {
		return 0
	}

	l := dfs(root.Left)
	r := dfs(root.Right)
	if l > r {
		ret += (l - r)
	} else {
		ret += (r - l)
	}
	return l + r + root.Val
}

func findTilt(root *TreeNode) int {
	dfs(root)
	return ret
}
