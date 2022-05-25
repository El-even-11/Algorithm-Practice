package main

func findSubstringInWraproundString(p string) int {
	n := len(p)
	dp := make([]int, n)
	dp[0] = 1
	max := make([]int, 26)
	max[p[0]-'a'] = 1
	for i := 1; i < n; i++ {
		if p[i]-'a' == (p[i-1]-'a'+1)%26 {
			dp[i] = dp[i-1] + 1
		} else {
			dp[i] = 1
		}
		if max[p[i]-'a'] < dp[i] {
			max[p[i]-'a'] = dp[i]
		}
	}

	sum := 0
	for _, a := range max {
		sum += a
	}

	return sum
}