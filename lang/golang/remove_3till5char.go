package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	inputFile, _ := os.Open("goprogram")
	outputFile, _ := os.OpenFile("goProgramT", os.O_WRONLY|os.O_CREATE, 0666)
	defer inputFile.Close()
	defer outputFile.Close()
	inputReader := bufio.NewReader(inputFile)
	outputWriter := bufio.NewWriter(outputFile)
	for {
		inputString, _, readError := inputReader.ReadLine()
		if readError == io.EOF {
			fmt.Println("EOF")
			return
			//break
		}
		//outputString := string([]byte(inputString)[2:5]) + "\n"
		outputString := string(inputString[2:5]) + "\n"
		fmt.Println(outputString)
		_, err := outputWriter.WriteString(outputString)
		if err != nil {
			fmt.Println(err)
			return
		}
		//without this line, it can not write the new file goProgramT
		outputWriter.Flush()
		fmt.Println("Conversion done")
	}
}
