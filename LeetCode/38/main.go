package main

import (
	"fmt"
)

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}

	s := "1"
	for i := 2; i <= n; i++ {
		var ss string
		ch := s[0]
		cnt := 1
		for j := 1; j < len(s); j++ {
			if s[j] == ch {
				cnt++
			} else {
				ss = ss + fmt.Sprintf("%d", cnt) + string(ch)
				ch = s[j]
				cnt = 1
			}
		}
		ss = ss + fmt.Sprintf("%d", cnt) + string(ch)
		s = ss
	}

	return s
}

func main() {

}
