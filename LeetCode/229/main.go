package main

func majorityElement(nums []int) []int {
	m := make(map[int]int)
	for _, a := range nums {
		m[a]++
	}
	var ret []int
	n := len(nums)
	for k, v := range m {
		if v > n/3 {
			ret = append(ret, k)
		}
	}

	return ret
}

func main() {

}
