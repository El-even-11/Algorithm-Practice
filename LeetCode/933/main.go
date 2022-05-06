package main

type RecentCounter struct {
	reqs []int
}


func Constructor() RecentCounter {
	return RecentCounter{
		reqs: make([]int, 0),
	}
}


func (this *RecentCounter) Ping(t int) int {
	this.reqs = append(this.reqs, t)
	for {
		if t-this.reqs[0]<=3000{
			break
		}
		this.reqs = this.reqs[1:]
	}

	return len(this.reqs)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */