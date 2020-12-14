package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func searchTree(bags map[string][]string, key string, value []string) int {

	var sum = 0

	for _, bag := range value {
		var number, _ = strconv.Atoi(strings.Split(bag, " ")[0])
		var bag = strings.Join(strings.Split(bag, " ")[1:], " ")
		sum += number + number*searchTree(bags, bag, bags[bag])
	}

	return sum
}

func main() {
	bags := make(map[string][]string)

	file, err := os.Open("in.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		var line = scanner.Text()
		var newbag = strings.Join(strings.Split(line, " ")[:2], " ")

		if !strings.Contains(line, "no other bags") {
			var removedExtra = strings.ReplaceAll(strings.ReplaceAll(strings.ReplaceAll(line, " bags", ""), " bag", ""), ".", "")
			bags[newbag] = strings.Split(strings.Split(removedExtra, " contain ")[1], ", ")
		}
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	fmt.Println(searchTree(bags, "shiny gold", bags["shiny gold"]))

}
