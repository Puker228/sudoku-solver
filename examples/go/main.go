package main

/*
#cgo CFLAGS: -I${SRCDIR}/../../src
#cgo LDFLAGS: -L${SRCDIR}/../../build -lsudoku -Wl,-rpath,${SRCDIR}/../../build
#include "solve.h"
*/
import "C"

import "fmt"

func main() {
	grid := [C.N][C.N]C.int{
		{0, 0, 3, 9, 0, 0, 0, 2, 6},
		{7, 0, 0, 0, 0, 8, 3, 0, 5},
		{0, 0, 0, 0, 0, 0, 0, 9, 0},
		{0, 0, 5, 0, 0, 0, 6, 0, 0},
		{4, 0, 0, 1, 8, 3, 0, 0, 0},
		{8, 0, 9, 0, 0, 6, 0, 3, 4},
		{0, 5, 2, 4, 1, 0, 7, 8, 0},
		{0, 8, 0, 3, 0, 0, 0, 0, 0},
		{3, 0, 0, 8, 0, 0, 2, 0, 9},
	}

	if C.solve_sudoku(&grid[0]) == 0 {
		fmt.Println("No solution")
		return
	}

	for _, row := range grid {
		fmt.Println(row)
	}
}
