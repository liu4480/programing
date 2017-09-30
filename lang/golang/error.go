package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	if len(os.Args) != 2 {
		os.Exit(1)
	}
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("not a valid number ", err)
	} else {
		fmt.Println(n)
	}
	file, err := os.Open("a_file_to_open")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()
}
