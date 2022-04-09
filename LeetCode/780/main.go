package main

func reachingPoints(sx int, sy int, tx int, ty int) bool {
	for tx != ty {
		if sx > tx || sy > ty {
			return false
		}

		if sx == tx {
			return (ty-sy)%sx == 0
		}

		if sy == ty {
			return (tx-sx)%sy == 0
		}

		if tx > ty {
			tx = tx % ty
		} else {
			ty = ty % tx
		}
	}

	return sx == tx && sy == ty
}
