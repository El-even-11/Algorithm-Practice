package main

func canIWin(n int, t int) bool {
	if n >= t {
		return true
	}

	sum := (1 + n) * n / 2

	if sum < t {
		return false
	}

	f := make([]int, 1<<n)
	for i := 0; i < 1<<n; i++ {
		f[i] = 0
	}

	var dfs func(state, now int) int
	dfs = func(state, now int) int {
		if f[state] != 0 {
			return f[state]
		}

		for i := 0; i < n; i++ {
			if ((state>>i)&1) == 1 {
				continue
			}
			if now+i+1 >= t {
				f[state] = 1
				return 1
			}
			if dfs(state|(i<<1), now+i+1) == -1 {
				f[state] = 1
				return 1
			}
		}
		f[state] = -1
		return -1
	}

	return dfs(0, 0) == 1
}
