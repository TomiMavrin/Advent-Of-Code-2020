package main

import (
	"strconv"
	"strings"
)

func checkCode(input []string) int {
	var cur = 0
	var acc = 0
	exec := make([]bool, len(input))

	for true {
		var cmd = strings.Split(input[cur], " ")[0]
		var val, _ = strconv.Atoi(strings.Split(input[cur], " ")[1])

		if exec[cur] {
			return 0
		}
		exec[cur] = true

		if cmd == "acc" {
			acc += val
			cur++
		} else if cmd == "jmp" {
			cur += val
		} else if cmd == "nop" {
			cur++
		}
		if cur > len(input)-1 {
			return acc
		}
	}
	return 0
}

func puzzleB(input []string) int {
	for index := range input {
		var bfr = input[index]

		if strings.Contains(input[index], "nop") {
			input[index] = strings.ReplaceAll(input[index], "nop", "jmp")
		} else if strings.Contains(input[index], "jmp") {
			input[index] = strings.ReplaceAll(input[index], "jmp", "nop")
		}

		var res = checkCode(input)
		if res != 0 {
			return res
		}

		input[index] = bfr
	}
	return 0
}
