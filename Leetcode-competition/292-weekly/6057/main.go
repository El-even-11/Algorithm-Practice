package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var sum map[*TreeNode]int
var cnt map[*TreeNode]int
var res int

func dfs(node *TreeNode) (int, int) {
	val := node.Val
	l := 0
	r := 0

	cntl := 0
	cntr := 0

	if node.Left != nil {
		if _, ok := sum[node.Left]; ok {
			l = sum[node.Left]
			cntl = cnt[node.Left]
		} else {
			l, cntl = dfs(node.Left)
			sum[node.Left] = l
			cnt[node.Left] = cntl
		}
	}

	if node.Right != nil {
		if _, ok := sum[node.Right]; ok {
			r = sum[node.Right]
			cntr = cnt[node.Right]
		} else {
			r, cntr = dfs(node.Right)
			sum[node.Right] = r
			cnt[node.Right] = cntr
		}
	}

	arr := (val + l + r) / (1 + cntl + cntr)

	if arr == val {
		res++
	}

	return val + l + r, 1 + cntl + cntr
}

func averageOfSubtree(root *TreeNode) int {
	sum = make(map[*TreeNode]int)
	cnt = make(map[*TreeNode]int)
	res = 0

	dfs(root)

	return res
}
