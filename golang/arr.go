package main
import "fmt"

func main() {
    //by default scores is initialize as {0,0,0,0,0,0,0,0,0,0}
    fmt.Println("array:")
    var scores [10]int
    fmt.Printf("%v\n", scores)
    scores[0] = 339
    fmt.Printf("%v\n", scores)
    fmt.Println(scores[0:4])
    for index, value := range scores {
        fmt.Printf("scores[%d]=%d\n", index, value)
    }

    fmt.Println("\n\nslice")
    scores1 := []int{1,4,293,4,9}
    fmt.Println(scores1)
    scores1[4] = 9033
    fmt.Println(scores1)
}
