package main

import (
	"fmt"
	"strconv"
)

var ret []string
var segs [4]int

func backtrack(s string, id, start int) {
	if id == 4 {
		if start == len(s) {
			ret = append(ret, fmt.Sprintf("%d.%d.%d.%d", segs[0], segs[1], segs[2], segs[3]))
		}
		return
	}

	if start == len(s) {
		return
	}

	if s[start] == '0' {
		segs[id] = 0
		backtrack(s, id+1, start+1)
		return
	}

	for end := start + 1; end <= len(s); end++ {
		addr, _ := strconv.Atoi(s[start:end])
		if addr <= 255 {
			segs[id] = addr
			backtrack(s, id+1, end)
		} else {
			break
		}
	}
}

func rettoreIpAddretses(s string) []string {
	if len(s) < 4 || len(s) > 12 {
		return nil
	}

	backtrack(s, 0, 0)
	return ret
}
