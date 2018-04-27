package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
)

type Book struct {
	title    string
	price    float64
	quantity int
}

func main() {
	bks := make([]Book, 1)
	file, err := os.Open("products.txt")
	if err != nil {
		log.Fatal("Error %s opening file products.txt:", err)
	}

	defer file.Close()

	reader := bufio.NewReader(file)
	for {
		line, err := reader.ReadString('\n')
		if err == io.EOF {
			break
		}

		line = string(line[:len(line)-2])

		strS1 := strings.Split(line, ";")
		book := new(Book)
		book.title = strS1[0]
		book.price, err = strconv.ParseFloat(strS1[1], 32)
		if err != nil {
			fmt.Printf("Error in file: %v", err)
		}

		book.quantity, err = strconv.Atoi(strS1[2])
		if err != nil {
			fmt.Printf("Error in file: %v", err)
		}

		if bks[0].title == "" {
			bks[0] = *book
		} else {
			bks = append(bks, *book)
		}
	}

	fmt.Println("We have read the following books from the file: ")
	for _, bk := range bks {
		fmt.Println(bk)
	}
}
