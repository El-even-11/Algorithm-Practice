package main

import (
	"fmt"
	"strconv"
	"strings"
)

func complexNumberMultiply(num1 string, num2 string) string {
	num1s := strings.Split(num1, "+")
	a1, _ := strconv.Atoi(num1s[0])
	b1, _ := strconv.Atoi(num1s[1][0 : len(num1s)-1])

	num2s := strings.Split(num2, "+")
	a2, _ := strconv.Atoi(num2s[0])
	b2, _ := strconv.Atoi(num2s[1][0 : len(num2s)-1])

	a3 := a1*a2 - b1*b2
	b3 := a1*b2 + a2*b1

	return fmt.Sprintf("%v+%vi", a3, b3)
}
