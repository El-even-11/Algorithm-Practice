package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(p *TreeNode, arr []int) {
	if p == nil {
		return
	}

	dfs(p.Left, arr)
	arr = append(arr, p.Val)
	dfs(p.Right, arr)
}

func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	arr1, arr2 := make([]int, 0), make([]int, 0)
	dfs(root1, arr1)
	dfs(root2, arr2)

	res := make([]int, 0)

	fmt.Println(arr1)
	fmt.Println(arr2)
	for i, j := 0, 0; len(res) < len(arr1)+len(arr2); {
		if i >= len(arr1) {
			res = append(res, arr2[j:]...)
		}
		if j >= len(arr2) {
			res = append(res, arr2[i:]...)
		}
		if arr1[i] < arr2[j] {
			res = append(res, arr1[i])
			i++
		} else {
			res = append(res, arr2[j])
			j++
		}
	}

	return res
}
