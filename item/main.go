package main

/*
#cgo CFLAGS : -I ../common/include
#cgo LDFLAGS : -L ../common/lib -l base
#include "info.h"
*/
import "C"

import (
	"fmt"
	"log"
)

//export RunSo
func RunSo(cb C.CallBack) {
	log.Println("----- Call Function From Golang So -------")
	log.Println("Hello Run So files.... ")
	C.Hello(C.int(3))
	C.Hello(C.int(3))
	C.Hello(C.int(3))
	C.Hello(C.int(3))
	log.Println("Call base.so director from golang file .!")
}

//export BoxHello
func BoxHello(message *C.char) *C.char {
	fmt.Println("Hello Box World !")
	fmt.Println("this is message ", C.GoString(message))
	return C.CString("this is message from golang !")
}

//export RunSoCallBack
func RunSoCallBack(cb C.CallBack) {
	C.runCallBack(cb)
}

func main() {
}
