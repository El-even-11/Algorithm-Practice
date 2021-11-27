package main

import (
	"math/rand"
	"time"
)

type Solution struct {
	m, n int
	mt   map[int]bool
}

func Constructor(m int, n int) Solution {
	rand.Seed(time.Now().Unix())
	return Solution{m: m, n: n, mt: make(map[int]bool)}
}

func (this *Solution) Flip() []int {
	a := rand.Intn(this.m * this.n)
	b := a
	for a >= 0 && this.mt[a] {
		a--
	}
	for b < this.m*this.n && this.mt[b] {
		a++
	}

	var c int
	if a >= 0 {
		if _, ok := this.mt[a]; !ok {
			c = a
		}
	}
	c = b

	this.mt[c] = true

	return []int{c / this.n, c % this.n}
}

func (this *Solution) Reset() {
	this.mt = make(map[int]bool)
}
