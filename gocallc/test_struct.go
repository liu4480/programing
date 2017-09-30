package main

/*
struct employee {
    char *id;
    int  age;
};
*/
import "C"

import "fmt"

//import "unsafe"

func main() {
	id := C.CString("1247")
	//too few values in struct initializer
	//var employee C.struct_employee = C.struct_employee{id, 21}
	var employee C.struct_employee = C.struct_employee{id: id, age: 21}
	fmt.Println(C.GoString(employee.id))
	fmt.Println(employee.age)
	//C.free(unsafe.Pointer(id))
}
