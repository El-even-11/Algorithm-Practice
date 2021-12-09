package main

func validTicTacToe(board []string) bool {

	// ' ' 0
	// 'X' 1
	// 'O' 2
	mat := [][]int{}
	for i := 0; i < 3; i++ {
		mat = append(mat, []int{})
		for j := 0; j < 3; j++ {
			if board[i][j] == ' ' {
				mat[i] = append(mat[i], 0)
			} else if board[i][j] == 'X' {
				mat[i] = append(mat[i], 1)
			} else {
				mat[i] = append(mat[i], 2)
			}
		}
	}

	Xcnt := 0
	Ocnt := 0

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if mat[i][j] == 1 {
				Xcnt++
			} else if mat[i][j] == 2 {
				Ocnt++
			}
		}
	}

	if Xcnt != Ocnt && Xcnt != Ocnt+1 {
		return false
	}

	xcnt := 0
	ocnt := 0
	for i := 0; i < 3; i++ {
		xcnt1 := 0
		xcnt2 := 0
		ocnt1 := 0
		ocnt2 := 0
		for j := 0; j < 3; j++ {
			if mat[i][j] == 1 {
				xcnt1++
			}
			if mat[j][i] == 1 {
				xcnt2++
			}
			if mat[i][j] == 2 {
				ocnt1++
			}
			if mat[j][i] == 2 {
				ocnt2++
			}
		}
		if xcnt1 == 3 {
			xcnt++
		}
		if xcnt2 == 3 {
			xcnt++
		}
		if ocnt1 == 3 {
			ocnt++
		}
		if ocnt2 == 3 {
			ocnt++
		}
	}

	xcnt1 := 0
	xcnt2 := 0
	ocnt1 := 0
	ocnt2 := 0
	for i := 0; i < 3; i++ {
		if mat[i][i] == 1 {
			xcnt1++
		}
		if mat[2-i][i] == 1 {
			xcnt2++
		}
		if mat[i][i] == 2 {
			ocnt1++
		}
		if mat[2-i][i] == 2 {
			ocnt2++
		}
	}
	if xcnt1 == 3 {
		xcnt++
	}
	if xcnt2 == 3 {
		xcnt++
	}
	if ocnt1 == 3 {
		ocnt++
	}
	if ocnt2 == 3 {
		ocnt++
	}

	if xcnt == 1 && ocnt == 1 {
		return false
	}

    if xcnt == 1 && Xcnt == Ocnt{
        return false
    }

    if ocnt == 1 && Xcnt == Ocnt + 1{
        return false
    }

	return true
}