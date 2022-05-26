package main

type Node struct {
	ls, rs, val, add int
}

const N int = 1e9

type Tree struct {
	cnt int
	tr  []*Node
}

func (tree *Tree) update(u, lc, rc, l, r, v int) {
	if l <= lc && rc <= r {
		tree.tr[u].val = v
		tree.tr[u].add = v
		return
	}

	tree.pushdown(u)
	mid := lc + rc>>1
	if l <= mid {
		tree.update(tree.tr[u].ls, lc, mid, l, r, v)
	}
	if r > mid {
		tree.update(tree.tr[u].rs, mid+1, rc, l, r, v)
	}
	tree.pushup(u)
}

func (tree *Tree) pushdown(u int) {
	if tree.tr[u] == nil {
		tree.tr[u] = &Node{}
	}
	if tree.tr[u].ls == 0 {
		tree.tr[u].ls = tree.cnt
		tree.cnt++
		tree.tr[tree.tr[u].ls] = &Node{}
	}
	if tree.tr[u].rs == 0 {
		tree.tr[u].rs = tree.cnt
		tree.cnt++
		tree.tr[tree.tr[u].rs] = &Node{}
	}

	if tree.tr[u].add == 0 {
		return
	}

	add := tree.tr[u].add
	tree.tr[tree.tr[u].ls].add = add
	tree.tr[tree.tr[u].ls].val = add
	tree.tr[tree.tr[u].rs].add = add
	tree.tr[tree.tr[u].rs].val = add
	tree.tr[u].add = 0
}

func (tree *Tree) pushup(u int) {
	if tree.tr[tree.tr[u].ls].val > tree.tr[tree.tr[u].rs].val {
		tree.tr[u].val = tree.tr[tree.tr[u].ls].val
	} else {
		tree.tr[u].val = tree.tr[tree.tr[u].rs].val
	}

}

func (tree *Tree) query(u, lc, rc, l, r int) int {
	if l <= lc && rc <= r {
		return tree.tr[u].val
	}
	tree.pushdown(u)
	mid := lc + rc>>1
	ans := 0
	if l <= mid {
		ans = tree.query(tree.tr[u].ls, lc, mid, l, r)
	}
	if r > mid {
		t := tree.query(tree.tr[u].rs, mid+1, rc, l, r)
		if t > ans {
			ans = t
		}
	}

	return ans
}

func fallingSquares(positions [][]int) []int {
	tree := Tree{
		cnt: 0,
		tr:  make([]*Node, 1000010),
	}
	ans := []int{}
	tree.tr[1] = &Node{}
	for _, p := range positions {
		x := p[0]
		h := p[1]
		cur := tree.query(1, 1, N, x, x+h-1)
		tree.update(1, 1, N, x, x+h-1, cur+h)
		ans = append(ans, tree.tr[1].val)
	}

	return ans
}
