package main

func minMoves(nums []int) int {
	min := nums[0]
	for x:= range nums {
		if min>x{
			min=x
		}
	}
	ret := 0
	for x:= range nums {
		ret+=(x-min)
	}	
	return ret
}

func main(){

}