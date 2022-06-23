package main

import "sort"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func largestValues(root *TreeNode) []int {
	m := make(map[int]int)

	var dfs func(root *TreeNode, depth int)
	dfs = func(root *TreeNode, depth int) {
		if root == nil {
			return
		}
		if _, ok := m[depth]; !ok || root.Val > m[depth] {
			m[depth] = root.Val
		}
		dfs(root.Left, depth+1)
		dfs(root.Right, depth+1)
	}

	dfs(root, 0)
	keys := make([]int, 0)
	for k := range m {
		keys = append(keys, k)
	}

	sort.Ints(keys)

	res := make([]int, 0)
	for _, k := range keys {
		res = append(res, m[k])
	}

	return res
}
