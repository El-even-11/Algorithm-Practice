package main

func lexicalOrder(n int) []int {
	cur := 1

	res := []int{}
	for len(res) < n {
		res = append(res, cur)
		if cur*10 <= n {
			cur *= 10
		} else if cur+1 <= n {
			for cur%10 == 9 {
				cur /= 10
			}
			cur++
		} else if cur == n {
			cur /= 10
			for cur%10 == 9 {
				cur /= 10
			}
			cur++
		} else {
			cur /= 10
			cur++
		}
	}

	return res
}