package main

/**
* @file json.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-08
 */

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
)

type Address struct {
	Type    string
	City    string
	Country string
}

type VCard struct {
	Firstname string
	LastName  string
	Addresses []*Address
	Remark    string
}

type Status struct {
	Text string
}

type User struct {
	Status Status
}

func main() {
	pa := &Address{"private", "Aartselaar", "Belgium"}
	wa := &Address{"work", "Boom", "Belgium"}
	vc := VCard{"Jan", "Kersschot", []*Address{pa, wa}, "none"}

	js, _ := json.Marshal(vc)
	fmt.Printf("JSON format: %s", js)

	file, _ := os.OpenFile("vcard.json", os.O_CREATE|os.O_WRONLY, 0666)
	defer file.Close()
	enc := json.NewEncoder(file)
	err := enc.Encode(vc)
	if err != nil {
		log.Println("Error in encoding json")
	}

	res, _ := http.Get("http://twitter.com/users/Googland.json")
	/* initialize the structure of the JSON response */
	user := User{Status{""}}
	/* unmarshal the JSON into our structures */
	temp, _ := ioutil.ReadAll(res.Body)
	body := []byte(temp)
	json.Unmarshal(body, &user)
	fmt.Printf("status: %s", user.Status.Text)
}
