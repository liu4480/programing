package main

/**
* @file panic_user.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-08
 */
import "fmt"
import "os"

func check(user string) {
	if user == "" {
		//panic("Unknow user: no value for $USER")
		defer func() {
			fmt.Println("Done")
			if err := recover(); err != nil {
				fmt.Printf("run time panic: %v", err)
			}
		}()
		panic("Unknow user: no value for $USER")
	}
	fmt.Println("found user:", user)
}

func main() {
	user := os.Getenv("USER")
	check(user)
	check("")
}
