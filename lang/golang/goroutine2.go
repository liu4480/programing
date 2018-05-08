package main

import (
	"fmt"
	//	"time"
)

func main() {
	ch := make(chan string)
	ch1 := make(chan bool)

	go sendData(ch)
	go getData(ch, ch1)

	//time.Sleep(time.Second)
	<-ch1
	//close(ch1)
}

func sendData(ch chan string) {
	ch <- "Washington"
	ch <- "Tripoli"
	ch <- "London"
	ch <- "Beijing"
	ch <- "Tokio"
}

func getData(ch chan string, ch1 chan bool) {
	var input string

	for i := 0; i < 5; i++ {
		input = <-ch
		fmt.Printf("%s\n", input)
	}
	close(ch)
	ch1 <- true
}
