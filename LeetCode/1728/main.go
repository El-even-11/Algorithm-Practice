// 177/178

package main

import "fmt"

type Box struct {
	x, y int
	t    byte
	time int
}

func canMouseWin(_grid []string, catJump int, mouseJump int) bool {
	m := len(_grid)
	n := len(_grid[0])
	grid := make([][]Box, m)
	for i := 0; i < m; i++ {
		grid[i] = make([]Box, n)
	}

	mouse := Box{}
	cat := Box{}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			grid[i][j] = Box{
				x:    i,
				y:    j,
				t:    _grid[i][j],
				time: 0,
			}

			if grid[i][j].t == 'M' {
				mouse = grid[i][j]
			} else if grid[i][j].t == 'C' {
				cat = grid[i][j]
			}
		}
	}

	q := make([]Box, 0)
	q = append(q, mouse)
	q = append(q, cat)

	getPos := func(x, y int, jump int) [][]int {

		pos := make([][]int, 0)

		// up
		for i := 1; i <= jump; i++ {
			dx := x - i
			if dx < 0 || grid[dx][y].t == '#' {
				break
			}
			pos = append(pos, []int{dx, y})
		}
		// down
		for i := 1; i <= jump; i++ {
			dx := x + i
			if dx >= m || grid[dx][y].t == '#' {
				break
			}
			pos = append(pos, []int{dx, y})
		}
		// left
		for i := 1; i <= jump; i++ {
			dy := y - i
			if dy < 0 || grid[x][dy].t == '#' {
				break
			}
			pos = append(pos, []int{x, dy})
		}
		// right
		for i := 1; i <= jump; i++ {
			dy := y + i
			if dy >= n || grid[x][dy].t == '#' {
				break
			}
			pos = append(pos, []int{x, dy})
		}

		return pos
	}

	time := 1
	for len(q) > 0 && time <= 1000 {
		l := len(q)
		for k := 0; k < l; k++ {
			animal := q[k]
			if animal.t == 'M' {
				pos := getPos(animal.x, animal.y, mouseJump)
				for _, p := range pos {

					if grid[p[0]][p[1]].t == 'F' {
						return true
					}

					if grid[p[0]][p[1]].t == 'M' || grid[p[0]][p[1]].t == 'C' && grid[p[0]][p[1]].time == time-1 {
						continue
					}

					grid[p[0]][p[1]] = Box{
						x:    p[0],
						y:    p[1],
						t:    'M',
						time: time,
					}
				}
			} else {
				pos := getPos(animal.x, animal.y, catJump)
				for _, p := range pos {

					if grid[p[0]][p[1]].t == 'F' {
						return false
					}

					if grid[p[0]][p[1]].t == 'C' {
						continue
					}

					grid[p[0]][p[1]] = Box{
						x:    p[0],
						y:    p[1],
						t:    'C',
						time: time,
					}
				}
			}
		}
		q = make([]Box, 0)
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j].time == time && grid[i][j].t == 'M' {
					q = append(q, grid[i][j])
				}
			}
		}

		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j].time == time && grid[i][j].t == 'C' {
					q = append(q, grid[i][j])
				}
			}
		}

		time++
	}

	return false
}

func main() {
	grid := []string{
		".M...",
		"..#..",
		"#..#.",
		"C#.#.",
		"...#F",
	}

	fmt.Println(canMouseWin(grid, 2, 5))
}

