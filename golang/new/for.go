package main

/**
* @file for.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2017-05-05
 */

import "fmt"

func main() {
	i := 3
	for i <= 3 {
		fmt.Println(i)
		i = i + 1
	}

	for j := 7; j < 9; j++ {
		fmt.Println(j)
	}

	for {
		fmt.Println("loop")
		break
	}

	for n := 0; n <= 5; n++ {
		if n%2 == 0 {
			continue
		}
		fmt.Println(n)
	}
}
