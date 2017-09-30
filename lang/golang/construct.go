package main

import "fmt"

type Saiyan struct {
    Name string
    Power int
}

func NewSaiyan1(name string, power int) *Saiyan {
    return &Saiyan{
        Name: name,
        Power: power,
    }
}

func NewSaiyan2(name string, power int) Saiyan {
    return Saiyan{
        Name: name,
        Power: power,
    }
}

func main() {
    goku1 := NewSaiyan1("goku1",100)
    goku2 := NewSaiyan2("goku2",200)
    fmt.Printf("goku1:%v\n", goku1)
    fmt.Printf("goku2:%v\n", goku2)
    goku := new(Saiyan)
    goku.Name = "googgle"
    goku.Power = 300
    fmt.Printf("goku:%v\n", goku)
}
