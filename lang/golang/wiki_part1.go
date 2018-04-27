package main

/**
* @file wiki_part1.go
* @brief
* @author bliu@suse.com
* @version 0.1.00
* @date 2018-05-07
 */

import (
	"fmt"
	"io/ioutil"
)

type Page struct {
	Title string
	Body  []byte
}

func (this *Page) save() (err error) {
	return ioutil.WriteFile(this.Title, this.Body, 0666)
}

func (this *Page) load(title string) (err error) {
	this.Title = title
	this.Body, err = ioutil.ReadFile(this.Title)
	return err
}

func main() {
	page := Page{
		"Page.md",
		[]byte("# Page\n## Section1\nThis is section"),
	}
	page.save()

	var new_page Page
	new_page.load("Page.md")
	fmt.Println(string(new_page.Body))
}
