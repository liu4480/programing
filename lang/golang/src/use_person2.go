package main

import (
	"./person"
	"fmt"
)

func main() {
	p := new(person.Person)
	p.SetFirstName("Alex")
	fmt.Println(p.FirstName())
}
