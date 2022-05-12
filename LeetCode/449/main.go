package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	arr := []int{}

	var inorder func(p *TreeNode)
	inorder = func(p *TreeNode) {
		if p == nil {
			return
		}
		inorder(p.Left)
		arr = append(arr, p.Val)
		inorder(p.Right)
	}
	inorder(root)

	return fmt.Sprintf("%v", arr)
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	return nil
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor()
 * deser := Constructor()
 * tree := ser.serialize(root)
 * ans := deser.deserialize(tree)
 * return ans
 */
