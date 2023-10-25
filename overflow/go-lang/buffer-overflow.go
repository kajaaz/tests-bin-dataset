package main

import (
	"fmt"
	"unsafe"
)

func vulnerableFunction(userInput []byte) {
	var buffer [10]byte
	for i := 0; i < len(userInput); i++ {
		buffer[i] = userInput[i]  // This line causes a buffer overflow when userInput is longer than 10 bytes
	}
	fmt.Println(string(buffer[:]))
}

func main() {
	var input string
	fmt.Println("Enter input:")
	fmt.Scan(&input)
	vulnerableFunction([]byte(input))
	// This line demonstrates the issue by printing the address of buffer
	fmt.Printf("Address of buffer: %p\n", unsafe.Pointer(&input))
}
