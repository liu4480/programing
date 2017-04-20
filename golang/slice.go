package main

import (
    "fmt"
    "math/rand"
    "sort"
)

type Saiyans struct {
    Name string
    Power int
}
func try_score() {
    scores := make([]int, 0, 5)
    c := cap(scores)
    fmt.Println(scores)
    for i:= 0; i < 25; i++ {
        scores = append(scores, i)
        if cap(scores) != c{
            c = cap(scores)
            fmt.Println(c)
        }
    }
    fmt.Println(scores)
}

func extractPowers1(saiyans []*Saiyans) []int {
    powers := make([]int, len(saiyans))
    for index, saiya := range saiyans {
        powers[index] = saiya.Power
    }
    return powers
}

func extractPowers2(saiyans []*Saiyans) []int {
    powers := make([]int, 0, len(saiyans))
    for _, saiya := range saiyans {
        powers = append(powers, saiya.Power)
    }
    return powers
}

func main () {
    fmt.Println("--------------------------------------------------------------------")
    fmt.Println("calling try_score:\n")
    try_score()
    fmt.Println("--------------------------------------------------------------------")
    fmt.Println("----------------------calling extractPowers1------------------------")
    saiyans := []*Saiyans{&Saiyans{"alex", 1},&Saiyans{"bruce", 2},&Saiyans{"tom", 3}}
    fmt.Println(extractPowers1(saiyans))
    fmt.Println("--------------------------------------------------------------------")
    fmt.Println("----------------------calling extractPowers1------------------------")
    fmt.Println(extractPowers2(saiyans))

    fmt.Println("--------------------------------------------------------------------")
    scores := make([]int, 100)
    for i := 0; i < 100; i++ {
        scores[i] = int(rand.Int31n(1000))
    }
    sort.Ints(scores)
    worst := make([]int, 5)
    copy(worst, scores[:5])
    fmt.Println(worst)
}
