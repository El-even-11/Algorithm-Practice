package main

import "container/heap"

func largestSumAfterKNegations(nums []int, k int) int {

	h := &IntHeap{}

	heap.Init(h)
	for _, a := range nums {
		heap.Push(h, a)
	}

	for i := 0; i < k; i++ {
		t := heap.Pop(h).(int)
		t = -t
		heap.Push(h, t)
	}

	ret := 0

	for i := 0; i < len(nums); i++ {
		ret += heap.Pop(h).(int)
	}

	return ret
}

type IntHeap []int

func (h IntHeap) Len() int { return len(h) }

func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
