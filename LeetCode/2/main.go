package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	p := l1
	q := l2

	for p.Next != nil && q.Next != nil {
		p = p.Next
		q = q.Next
	}

	if p.Next == nil && q.Next != nil {
		for q.Next != nil {
			p.Next = &ListNode{
				Val: 0,
			}
			p = p.Next
			q = q.Next
		}
	}

	if p.Next != nil && q.Next == nil {
		for p.Next != nil {
			q.Next = &ListNode{
				Val: 0,
			}
			p = p.Next
			q = q.Next
		}
	}

	carry := 0
	res := &ListNode{}
	t := res

	for l1.Next != nil && l2.Next != nil {
		t.Val = (l1.Val + l2.Val + carry) % 10
		carry = (l1.Val + l2.Val + carry) / 10
		t.Next = &ListNode{}
		l1 = l1.Next
		l2 = l2.Next
		t = t.Next
	}

	t.Val = (l1.Val + l2.Val + carry) % 10
	carry = (l1.Val + l2.Val + carry) / 10

	if carry == 1 {
		t.Next = &ListNode{
			Val: 1,
		}
	}

	return res
}
