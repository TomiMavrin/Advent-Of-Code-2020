package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func scanInput() []string {
	var input []string

	file, err := os.Open("in.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		input = append(input, scanner.Text())
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	return input
}

func main() {
	var input = scanInput()

	fmt.Println("A: ", puzzleA(input))
	fmt.Println("B: ", puzzleB(input))
}
