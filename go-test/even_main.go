package main

import "fmt"
import "even/even"

func main() {
	for i := 0; i <= 100; i++ {
		fmt.Printf("Is the integer %s even? %v\n", i, even.Even(i))
	}
}
