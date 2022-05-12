package main

func minDeletionSize(strs []string) int {
	m := len(strs)
	n := len(strs[0])
	cnt := 0
	for j := 0; j < n; j++ {
		pre := strs[0][j]
		for i := 1; i < m; i++ {
			if strs[i][j] < pre {
				cnt++
				break
			}
			pre = strs[i][j]
		}
	}

	return cnt
}
