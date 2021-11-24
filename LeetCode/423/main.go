package main

import (
	"strconv"
	"strings"
)

func originalDigits(s string) string {
	m := make(map[rune]int)

	for _, c := range "abcdefghijklmnopqrstuvwxyz" {
		m[c] = 0
	}

	for _, c := range s {
		m[c]++
	}

	cnt := make([]int, 10)

	cnt[0] = m['z']
	cnt[2] = m['w']
	cnt[8] = m['g']
	cnt[6] = m['x']
	cnt[7] = m['s'] - cnt[6]
	cnt[5] = m['v'] - cnt[7]
	cnt[9] = m['i'] - cnt[5] - cnt[6] - cnt[8]
	cnt[5] = m['f'] - cnt[5]
	cnt[3] = m['r'] - cnt[0] - cnt[4]
	cnt[1] = m['o'] - cnt[0] - cnt[2] - cnt[4]

	var ret []string
	for i := 0; i < 10; i++ {
		for j := 0; j < cnt[i]; j++ {
			ret = append(ret, strconv.Itoa(i))
		}
	}

	return strings.Join(ret, "")
}
