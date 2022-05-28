package main

import (
	"strings"
)

func removeOuterParentheses(s string) string {
	if len(s) == 0 {
		return ""
	}
	l, r := 0, 1
	n := len(s)
	writer := strings.Builder{}
	cnt := 1
	for l < n && r < n {
		if s[r] == '(' {
			cnt++
		} else {
			cnt--
		}

		r++
		if cnt == 0 {
			writer.WriteString(s[l+1 : r-1])
			l = r
		}
	}

	return writer.String()
}
