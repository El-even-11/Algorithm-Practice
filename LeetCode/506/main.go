package main

import (
	"sort"
	"strconv"
)

func findRelativeRanks(score []int) []string {
	tmp := make([]int, len(score))
	copy(tmp, score)

	sort.Ints(score)

	m := make(map[int]string)

	for i := len(score) - 1; i >= 0; i-- {
		if i == len(score)-1 {
			m[score[i]] = "Gold Medal"
		} else if i == len(score)-2 {
			m[score[i]] = "Silver Medal"
		} else if i == len(score)-3 {
			m[score[i]] = "Bronze Medal"
		} else {
			m[score[i]] = strconv.Itoa(len(score) - i)
		}
	}

	ret := []string{}

	for i := 0; i < len(tmp); i++ {
		ret = append(ret, m[tmp[i]])
	}

	return ret
}
