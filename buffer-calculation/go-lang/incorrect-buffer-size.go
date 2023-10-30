package main

import (
	"fmt"
)

func vulnerableFunction(src []byte) {
	// Incorrectly calculating buffer size
	bufSize := len(src) - 1
	dst := make([]byte, bufSize)
	copy(dst, src)  // This line could lead to an out-of-bounds read if src has a length of 0

	fmt.Println(string(dst))
}

func main() {
	data := []byte("hello, world")
	vulnerableFunction(data)
}
