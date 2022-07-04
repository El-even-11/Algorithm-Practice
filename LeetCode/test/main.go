package main

import "time"

func main() {
	chpool := make([]chan int, 1)
	go func() {
		time.Sleep(10 * time.Second)
		println("here2")
		chpool[0] = make(chan int)
	}()

	println("here1")
	go func() {
		println("here4")		
		chpool[0] <- 1
		println("here5")	
	}()
	<-chpool[0]
	println("here3")
}
