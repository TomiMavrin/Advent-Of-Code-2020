package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func main() {
	colors := make(map[string]int)
	colors["shiny gold"] = 1

	file, err := os.Open("in.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	var lines []string

	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	var flag = true

	for flag {
		newColors := make(map[string]int)
		for _, line := range lines {
			for key := range colors {
				if strings.Contains(line, key) {
					var newbag = strings.Join(strings.Split(line, " ")[:2], " ")
					if colors[newbag] == 0 {
						newColors[newbag] = 1
					}
				}
			}
		}
		flag = len(newColors) > 0

		for c := range newColors {
			colors[c] = 1
		}
	}

	fmt.Println(len(colors) - 1)
}
