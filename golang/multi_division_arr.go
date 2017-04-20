package main

import "fmt"

func main () {
    var arr [4][2]int

    arr = [4][2]int{{10,11},{20,21},{30,31},{40,41}}
    fmt.Println(arr)

    arr[1] = [2]int{0,0}
    fmt.Println(arr)
}
