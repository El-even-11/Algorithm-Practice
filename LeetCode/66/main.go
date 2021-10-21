package main

func plusOne(digits []int) []int {
	digits = append(digits, 0)
	copy(digits[1:], digits[:])
	digits[0] = 1

	ok := false
	i := len(digits) - 1

	for !ok && i > 0 {
		if digits[i] != 9 {
			ok = true
			digits[i]++
		} else {
			digits[i] = 0
		}
		i--
	}

	if !ok {
		return digits
	}

	return digits[1:]
}

func main() {

}
