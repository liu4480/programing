package main

import (
    "fmt"
    "time"
    "sync"
)

var counter = 0

var (
    counter2 = 0
    lock sync.Mutex
)

func main() {
    for i := 0; i < 2; i++ {
        go incr()
    }
    time.Sleep(time.Millisecond * 10)
}

func incr() {
    counter++
    fmt.Println(counter)
}

func incr2() {
    lock.Lock()
    defer lock.Unlock()
    counter2++
    fmt.Println(counter2)
}
