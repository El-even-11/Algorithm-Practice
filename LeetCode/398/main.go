package main

import (
	"math/rand"
	"time"
)

type Solution struct {
	m map[int][]int
}

func Constructor(nums []int) Solution {
	rand.Seed(time.Now().Unix())

	s := Solution{}
	s.m = make(map[int][]int)

	for i, k := range nums {
		if _, ok := s.m[k]; !ok {
			s.m[k] = []int{}
		}
		s.m[k] = append(s.m[k], i)
	}

	return s
}

func (this *Solution) Pick(target int) int {
	idx := this.m[target]
	i := rand.Int() % len(idx)
	return idx[i]
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */
