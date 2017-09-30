package main
import (
    "fmt"
)

type Saiyan struct {
    Name string
    Power int
}

func main() {
    goku := Saiyan{"Goku", 9000}
    goku1 := &Saiyan{"Goku", 9000}
    goku2 := &Saiyan{"Goku", 9000}
    Super(goku)
    Super1(goku1)
    goku2.Super()
    fmt.Println(goku.Power)
    fmt.Println(goku1.Power)
    fmt.Println(goku2.Power)
    fmt.Printf("goku:%v\n", goku)
    fmt.Printf("goku1:%v\n", goku1)
    fmt.Printf("goku2:%v\n", goku1)
}

func Super(s Saiyan) {
    s.Power += 10000
}

func Super1(s *Saiyan) {
    s.Power += 10000
}

func (s *Saiyan) Super() {
    s.Power += 10000
}
