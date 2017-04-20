package main
import (
    "fmt"
    )

func main() {
    //var power int
    //power = 9000
    power := 9000
    fmt.Printf("default power is %d\n", power)
    /*no new variables on left side of :=*/
    //power := 9001
    //fmt.Println(power)
    name, power := "Goku", 1000
    fmt.Printf("%s's power is over %d\n", name, power)
}
