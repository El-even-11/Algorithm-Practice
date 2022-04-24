package main

func binaryGap(n int) int {
	bit := []int{}
	for n > 0 {
		bit = append(bit, n&1)
		n >>= 1
	}

	i := 0
	for ; i < len(bit); i++ {
		if bit[i] == 1 {
			break
		}
	}

	if i == len(bit) {
		return 0
	}

	dis := 0

	for i < len(bit) {
		j := i + 1
		for ; j < len(bit); j++ {
			if bit[j] == 1 {
				break
			}
		}
		if j == len(bit) {
			break
		}
		if j-i > dis {
			dis = j - i
		}
		i = j
	}

	return dis
}
