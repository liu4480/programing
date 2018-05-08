package main

/**
* @file gob2.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-08
 */

import (
	"bufio"
	"encoding/gob"
	"fmt"
	"log"
	"os"
)

type Address struct {
	Type    string
	City    string
	Country string
}

type VCard struct {
	FirstName string
	LastName  string
	Addresses []*Address
	Remark    string
}

var content string
var vc VCard

func gob_encode(filename string) (err error) {
	pa := &Address{"private", "Aartselaar", "Belgium"}
	wa := &Address{"work", "Boom", "Belgium"}
	vc := VCard{"Jan", "Kersschot", []*Address{pa, wa}, "none"}

	file, _ := os.OpenFile(filename, os.O_CREATE|os.O_WRONLY, 0666)
	defer file.Close()
	enc := gob.NewEncoder(file)
	err = enc.Encode(vc)
	return err
}

func gob_decode(filename string) (err error) {
	file, _ := os.Open(filename)
	defer file.Close()
	inReader := bufio.NewReader(file)
	dec := gob.NewDecoder(inReader)
	err = dec.Decode(&vc)
	return
}

func main() {
	err := gob_encode("vcard.gob")
	if err != nil {
		log.Fatal("Failed to encode gob")
	}

	err = gob_decode("vcard.gob")
	if err != nil {
		log.Fatal("Failed to decode gob")
	}
	fmt.Println(vc)
}
