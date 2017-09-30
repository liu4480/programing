package main

//#include <stdio.h>
//#include <stdlib.h>
//char * foo = "hellofoo";
import "C"

import "fmt"

func main() {
	fmt.Printf("%s\n", C.GoString(C.foo))
}
