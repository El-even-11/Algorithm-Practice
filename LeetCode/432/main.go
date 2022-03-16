package main

type AllOne struct {
	max   int
	min   int
	str2i map[string]int
	i2str map[int]map[string]bool
}

func Constructor() AllOne {
	allone := AllOne{
		max:   0,
		min:   0,
		str2i: make(map[string]int),
		i2str: make(map[int]map[string]bool),
	}
	return allone
}

func (this *AllOne) Inc(key string) {
	this.str2i[key]++
	cnt := this.str2i[key]
    if cnt > 1 {
		delete(this.i2str[cnt-1], key)
	}
	if cnt > this.max {
		this.max = cnt
	}
	if cnt < this.min {
		this.min = cnt
	}
	if this.i2str[cnt] == nil {
		this.i2str[cnt] = make(map[string]bool)
	}
	this.i2str[cnt][key] = true
	if this.i2str[this.min] == nil || len(this.i2str[this.min]) == 0 {
		this.min++
	}
}

func (this *AllOne) Dec(key string) {
	this.str2i[key]--
	cnt := this.str2i[key]
    delete(this.i2str[cnt+1], key)
	
	if cnt > 0 {
        if cnt < this.min{
            this.min = cnt
        }
		if this.i2str[cnt] == nil {
			this.i2str[cnt] = make(map[string]bool)
		}
        this.i2str[cnt][key] = true
	}
	
	if this.i2str[this.max] == nil || len(this.i2str[this.max]) == 0 {
		this.max--
	}
}

func (this *AllOne) GetMaxKey() string {
	for key := range this.i2str[this.max] {
		return key
	}
	return ""
}

func (this *AllOne) GetMinKey() string {
	for key := range this.i2str[this.min] {
		return key
	}
	return ""
}

func main() {
	obj := Constructor()
	obj.Inc("hello")
	obj.Inc("hello")
}
