package main

import (
	"math/rand"
	"time"
)

func repeatedNTimes(nums []int) int {
	rand.Seed(time.Now().Unix())
	n := len(nums)
	for {
		i := rand.Int() % n
		j := rand.Int() % n
		if i != j && nums[i] == nums[j] {
			return nums[i]
		}
	}

	return -1
}
