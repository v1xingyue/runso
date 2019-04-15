package main

/*
#cgo CFLAGS : -I /Users/xingyue/outcode/git/runso/common/include
#cgo LDFLAGS : -L/Users/xingyue/outcode/git/runso/common/lib -l base
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
	C.Hello(C.int(3))
	C.Hello(C.int(3))
	C.Hello(C.int(3))
	C.Hello(C.int(3))
}

//export BoxHello
func BoxHello(message *C.char) *C.char {
	fmt.Println("Hello Box World !")
	fmt.Println("this is message ", C.GoString(message))
	return C.CString("this is message from golang !")
}

func main() {
}
