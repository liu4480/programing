package main

/**
* @file const.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2017-05-05
 */

import (
	"fmt"
	"math"
)

const s string = "constant"

func main() {
	fmt.Println(s)

	const n = 5000000000000

	const d = 3e20 / n
	fmt.Println(d)

	fmt.Println(int64(d))

	fmt.Println(math.Sin(n))
}
