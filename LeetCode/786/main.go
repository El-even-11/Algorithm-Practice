package main

import (
	"container/heap"
)

func kthSmallestPrimeFraction(arr []int, k int) []int {
	h := &Heap{}
	heap.Init(h)

	for i := 0; i < len(arr)-1; i++ {
		for j := i + 1; j < len(arr); j++ {
			heap.Push(h, Fraction{arr[i], arr[j]})
		}
	}

	ret := []int{0, 0}
	for i := 0; i < k-1; i++ {
		heap.Pop(h)
	}
	f := heap.Pop(h).(Fraction)
	ret[0] = f.i
	ret[1] = f.j

	return ret
}

type Heap []Fraction

type Fraction struct {
	i, j int
}

func (h Heap) Len() int { return len(h) }

func (h Heap) Less(i, j int) bool { return h[i].i*h[j].j < h[i].j*h[j].i }

func (h Heap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(Fraction))
}
