package main

/**
* @file panic_recover.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-08
 */

import "fmt"

func badCall() {
	panic("bad end")
}

func test() {
	defer func() {
		if e := recover(); e != nil {
			fmt.Printf("Panicing %s\n", e)
		}
	}()
	badCall()
	fmt.Printf("After bad call\n")
}

func main() {
	fmt.Printf("calling test()\n")
	test()
	fmt.Printf("test() completed\n")
}
