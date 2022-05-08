package main

import "strconv"

const K = 1000000007

func countTexts(pressedKeys string) int {

	times := map[int]int{
		2: 3,
		3: 3,
		4: 3,
		5: 3,
		6: 3,
		7: 4,
		8: 3,
		9: 4,
	}

	res := 1

	i := 0
	dp3 := []int{1, 2, 4}
	dp4 := []int{1, 2, 4, 8}

	for i < len(pressedKeys) {
		j := i + 1
		for ; j < len(pressedKeys); j++ {
			if pressedKeys[i] != pressedKeys[j] {
				break
			}
		}

		l := j - i

		key, _ := strconv.Atoi(pressedKeys[i:i+1])
		k := times[key]

		ways := 0
		if k == 3 {
			for l > len(dp3) {
				dp3 = append(dp3, ((dp3[len(dp3)-1]+dp3[len(dp3)-2])%K+dp3[len(dp3)-3])%K)
			}
			ways = dp3[l-1] % K
		} else {
			for l > len(dp4) {
				dp4 = append(dp4, (((dp4[len(dp4)-1]+dp4[len(dp4)-2])%K+dp4[len(dp4)-3])%K+dp4[len(dp4)-4])%K)
			}
			ways = dp4[l-1] % K
		}

		i = j

		res = (res * ways) % K
	}

	return res
}

func main(){
	countTexts("222222222222222222222222222222222222")
}
