package main

import "fmt"

func badCall() {
	a, b := 10, 0
	n := a / b
	fmt.Println(n)
}

func test() {
	defer func() {
		if e := recover(); e != nil {
			fmt.Printf("Panicing %s\n", e)
		}
	}()
	badCall()
	fmt.Println("after bad call")
}

func main() {
	fmt.Printf("Calling test\r\n")
	test()
	fmt.Printf("test completed\n")
}
