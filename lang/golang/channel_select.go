package main

import (
    "fmt"
    "math/rand"
    "time"
)

func main() {
    c := make(chan int, 100) //with buffer
    //c := make(chan int) //without buffer
    for i := 0; i < 5; i++ {
        worker := &Worker{id: i}
        go worker.process(c)
    }
    for {
        select {
            case c <- rand.Int():
                fmt.Printf("gernerated data %d\n", c)
            case <-time.After(time.Millisecond * 100):
                fmt.Println("timed out")
            default:
                fmt.Println("dropped")
        }
        time.Sleep(time.Millisecond * 50)
    }
}

type Worker struct {
    id int
}

func(w *Worker) process(c chan int) {
    for {
        select {
        case data := <- c:
            fmt.Printf("worker %d got %d\n", w.id, data)
        case <-time.After(time.Millisecond * 100):
            fmt.Println("Break time")
            time.Sleep(time.Second)
        }
    }
}
