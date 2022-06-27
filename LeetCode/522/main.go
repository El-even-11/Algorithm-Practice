package main

import "sort"

type byLen []string

func (x byLen) Len() int {
	return len(x)
}

func (x byLen) Less(i, j int) bool {
	return len(x[i]) > len(x[j])
}

func (x byLen) Swap(i, j int) {
	x[i], x[j] = x[j], x[i]
}

func findLUSlength(strs []string) int {
	list := byLen{}
	for _, s := range strs {
		list = append(list, s)
	}

	sort.Sort(list)

	n := len(list)
	for i := 0; i < n; i++ {
		unique := true
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if len(list[i]) > len(list[j]) {
				break
			}
			p, q := 0, 0
			for p < len(list[i]) && q < len(list[j]) {
				if list[i][p] == list[j][q] {
					p++
					q++
				} else {
					q++
				}
			}

			if p == len(list[i]) {
				unique = false
			}
		}
		if unique {
			return len(list[i])
		}
	}

	return -1
}
