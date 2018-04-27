package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	inputReader := bufio.NewReader(os.Stdin)
	fmt.Println("Please enter your name:")
	input, err := inputReader.ReadString('\n')

	if err != nil {
		fmt.Println("There were errors resding, exiting program.")
		return
	}

	fmt.Printf("Your name is %s", input)
	switch input {
	case "Philip\n":
		fmt.Println("Welcome Philip!")
	case "Chris\n":
		fmt.Println("Welcome Chris!")
	case "Ivo\n":
		fmt.Println("Welcome Ivo!")
	default:
		fmt.Println("You are not welcome here! Goodbye!")
	}

	switch input {
	case "Philip\n":
		fallthrough
	case "Ivo\n":
		fallthrough
	case "Chris\n":
		fmt.Printf("Welcome %s", input)
	default:
		fmt.Printf("You are not welcome here! Goodbye!\n")
	}

	switch input {
	case "Philip\n", "Ivo\n":
		fmt.Printf("Welcome %s", input)
	default:
		fmt.Printf("You are not welcome here! Goodbye!\n")
	}
}
