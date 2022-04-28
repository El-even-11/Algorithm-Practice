package main

import "fmt"

func main() {
	g := [][]int{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
	}

	a := g[1:3][1:3]

	fmt.Println(a)
}
