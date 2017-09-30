/**
* @file map.go
* @brief 
* @author bliu@suse.com
* @version 0.1.00
* @date 2017-04-20
*/

package main

import "fmt"

type Saiyan struct {
    Name string
    Friends map[string] *Saiyan
}

func main() {
    fmt.Println("----------------------------------------------------------------")
    fmt.Println("--------------------------first map-----------------------------")
    lookup := make(map[string]int)
    lookup["goku"] = 9001
    lookup["krillin"] = 9002
    power, exists := lookup["vegeta"]

    fmt.Println(power, exists, len(lookup))
    fmt.Println()
    for key, value := range lookup {
        fmt.Println(key, value)
    }
    fmt.Println("----------------------------------------------------------------")
    fmt.Println("--------------------------struct map----------------------------")
    goku := &Saiyan{
        Name: "Goku",
        Friends: make(map[string]*Saiyan),
    }
    goku.Friends["krillin"] = &Saiyan{
        Name: "Krillin",
        Friends: make(map[string]*Saiyan),
    }
    fmt.Println(goku.Name)
    fmt.Println(goku.Friends)
}
