package main

/**
* @file filewrite.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-07
 */
import "os"

func main() {
	os.Stdout.WriteString("Hello, world\n")
	f, _ := os.OpenFile("test111", os.O_CREATE|os.O_WRONLY, 0)
	defer f.Close()
	f.WriteString("hello, world in a file\n")
}
