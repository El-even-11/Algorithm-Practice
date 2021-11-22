package main

import (
	"math/rand"
	"time"
)

type Solution struct {
	nums []int
}

func Constructor(nums []int) Solution {
	s := Solution{nums: nums}
	rand.Seed(time.Now().Unix())
	return s
}

func (this *Solution) Reset() []int {
	return this.nums
}

func (this *Solution) Shuffle() []int {
	n := len(this.nums)
	ret := make([]int, n)
	copy(ret, this.nums)

	for i := 0; i < n; i++ {
		j := rand.Intn(n-i) + i
		ret[i], ret[j] = ret[j], ret[i]
	}
	return ret
}
