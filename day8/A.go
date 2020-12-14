package main

import (
	"strconv"
	"strings"
)

func puzzleA(input []string) int {
	var cur = 0
	var acc = 0

	exec := make([]bool, len(input))

	for true {
		var cmd = strings.Split(input[cur], " ")[0]
		var val, _ = strconv.Atoi(strings.Split(input[cur], " ")[1])

		if exec[cur] {
			break
		} else {
			exec[cur] = true
		}

		if cmd == "acc" {
			acc += val
		} else if cmd == "jmp" {
			cur += val
			continue
		}
		cur++
	}

	return acc
}
