package main

import (
	"fmt"
	"math"
	"sort"
)

// some collinear cases would fail,

func outerTrees(trees [][]int) [][]int {

	n := len(trees)

	if n == 1 {
		return trees
	}

	minx := trees[0][0]
	miny := trees[0][1]

	p := 0
	for i := 1; i < n; i++ {
		if trees[i][1] < miny {
			p = i
			miny = trees[i][1]
		} else if trees[i][1] == miny {
			if trees[i][0] < minx {
				p = i
				minx = trees[i][0]
			}
		}
	}

	trees = append(trees[:p], trees[p+1:]...)

	angle := func(x, y int) float64 {
		return float64(x-minx) / float64(math.Sqrt(float64((x-minx)*(x-minx)+(y-miny)*(y-miny))))
	}

	sort.Slice(trees, func(i, j int) bool {
		return angle(trees[i][0], trees[i][1]) > angle(trees[j][0], trees[j][1])
	})

	fmt.Println(trees)

	res := [][]int{{minx, miny}, {trees[0][0], trees[0][1]}}

	trees = trees[1:]

	area := func(p1, p2, p3 []int) int {
		return (p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0])
	}

	for len(trees) > 0 {
		p1 := res[len(res)-2]
		p2 := res[len(res)-1]
		p3 := trees[0]
		a := area(p1, p2, p3)
		if a >= 0 {
			res = append(res, p3)
			trees = trees[1:]
		} else if a < 0 {
			res = res[:len(res)-1]
		} 
	}

	return res
}


// solution

// func cross(p, q, r []int) int {
//     return (q[0]-p[0])*(r[1]-q[1]) - (q[1]-p[1])*(r[0]-q[0])
// }

// func distance(p, q []int) int {
//     return (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1])
// }

// func outerTrees(trees [][]int) [][]int {
//     n := len(trees)
//     if n < 4 {
//         return trees
//     }

//     // 找到 y 最小的点 bottom
//     bottom := 0
//     for i, tree := range trees {
//         if tree[1] < trees[bottom][1] {
//             bottom = i
//         }
//     }
//     trees[bottom], trees[0] = trees[0], trees[bottom]

//     // 以 bottom 原点，按照极坐标的角度大小进行排序
//     tr := trees[1:]
//     sort.Slice(tr, func(i, j int) bool {
//         a, b := tr[i], tr[j]
//         diff := cross(trees[0], a, b) - cross(trees[0], b, a)
//         return diff > 0 || diff == 0 && distance(trees[0], a) < distance(trees[0], b)
//     })

//     // 对于凸包最后且在同一条直线的元素按照距离从小到大进行排序
//     r := n - 1
//     for r >= 0 && cross(trees[0], trees[n-1], trees[r]) == 0 {
//         r--
//     }
//     for l, h := r+1, n-1; l < h; l++ {
//         trees[l], trees[h] = trees[h], trees[l]
//         h--
//     }

//     st := []int{0, 1}
//     for i := 2; i < n; i++ {
//         // 如果当前元素与栈顶的两个元素构成的向量顺时针旋转，则弹出栈顶元素
//         for len(st) > 1 && cross(trees[st[len(st)-2]], trees[st[len(st)-1]], trees[i]) < 0 {
//             st = st[:len(st)-1]
//         }
//         st = append(st, i)
//     }

//     ans := make([][]int, len(st))
//     for i, idx := range st {
//         ans[i] = trees[idx]
//     }
//     return ans
// }
