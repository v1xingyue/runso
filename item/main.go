package main

/*
#include "info.h"
*/
import "C"

import (
	"fmt"
	"log"
)

//export RunSo
func RunSo() {
	log.Println("----- Call Function From Golang So -------")
	log.Println("Hello Run So files.... ")
	C.Hello()
}

//export BoxHello
func BoxHello(message *C.char) *C.char {
	fmt.Println("Hello Box World !")
	fmt.Println("this is message ", C.GoString(message))
	return C.CString("this is message from golang !")
}

func main() {
}
