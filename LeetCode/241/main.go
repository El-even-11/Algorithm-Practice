package main

import (
	"strconv"
)

func diffWaysToCompute(expression string) []int {
	return dfs(0, len(expression)-1, expression)
}

func dfs(l, r int, s string) []int {
	ans := []int{}
	for i := l; i <= r; i++ {
		if s[i] >= '0' && s[i] <= '9' {
			continue
		}
		lans := dfs(l, i-1, s)
		rans := dfs(i+1, r, s)
		for _, a := range lans {
			for _, b := range rans {
				switch s[i] {
				case '+':
					ans = append(ans, a+b)
				case '-':
					ans = append(ans, a-b)
				case '*':
					ans = append(ans, a*b)
				default:
					panic("invalid operand")
				}
			}
		}
	}

	if len(ans) == 0 {
		num, _ := strconv.Atoi(s[l : r+1])
		ans = append(ans, num)
	}

	return ans
}
