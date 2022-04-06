package main

func findMinHeightTrees(n int, edges [][]int) []int {
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = []int{i}
	}

	for _, edge := range edges {
		g[edge[0]] = append(g[edge[0]], edge[1])
		g[edge[1]] = append(g[edge[1]], edge[0])
	}

	cnt := n
	for cnt > 2 {
		a := []int{}
		b := []int{}

		for i, v := range g {
			if len(v) == 2 {
				a = append(a, i)
				b = append(b, v[1])
				cnt--
			}
		}

		for i := 0; i < len(a); i++ {
			g[a[i]] = []int{}
			j := 1
			for ; j < len(g[b[i]]); j++ {
				if g[b[i]][j] == a[i] {
					break
				}
			}
			g[b[i]] = append(g[b[i]][:j], g[b[i]][j+1:]...)
		}
	}

	ret := []int{}
	for i, v := range g {
		if len(v) > 0 {
			ret = append(ret, i)
		}
	}

	return ret
}

func main() {
	findMinHeightTrees(6, [][]int{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}})
}
