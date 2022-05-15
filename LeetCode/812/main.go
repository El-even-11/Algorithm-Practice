package main

import "math"

func largestTriangleArea(points [][]int) float64 {
	n := len(points)
	max := 0.0
	for i := 0; i < n; i++ {
		a := points[i]
		for j := i + 1; j < n; j++ {
			b := points[j]
			for k := j + 1; k < n; k++ {
				c := points[k]
				ax := c[0] - a[0]
				ay := c[1] - a[1]
				bx := c[0] - b[0]
				by := c[1] - b[1]
				if math.Abs(float64(ax*by-ay*bx)) > max {
					max = math.Abs(float64(ax*by - ay*bx))
				}
			}
		}
	}

	return max / 2.0
}
