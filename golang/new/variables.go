package main

/**
* @file variables.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2017-05-05
 */

import "fmt"

func main() {
	var a string = "initial"
	fmt.Println(a)

	var b, c int = 1, 2
	fmt.Println(b, c)

	var d = true
	fmt.Println(d)

	var e int
	fmt.Println(e)

	f := "short"
	fmt.Println(f)
}
