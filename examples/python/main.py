import ctypes

# Replace the library file with the one suitable for your OS.
lib = ctypes.CDLL("./libsudoku.dylib")

lib.solve_sudoku.argtypes = [ctypes.POINTER(ctypes.c_int)]
lib.solve_sudoku.restype = ctypes.c_int


def main():
    Row = ctypes.c_int * 9
    Grid = Row * 9

    grid = Grid(
        *(
            Row(*row)
            for row in [
                [0, 0, 3, 9, 0, 0, 0, 2, 6],
                [7, 0, 0, 0, 0, 8, 3, 0, 5],
                [0, 0, 0, 0, 0, 0, 0, 9, 0],
                [0, 0, 5, 0, 0, 0, 6, 0, 0],
                [4, 0, 0, 1, 8, 3, 0, 0, 0],
                [8, 0, 9, 0, 0, 6, 0, 3, 4],
                [0, 5, 2, 4, 1, 0, 7, 8, 0],
                [0, 8, 0, 3, 0, 0, 0, 0, 0],
                [3, 0, 0, 8, 0, 0, 2, 0, 9],
            ]
        )
    )
    result = lib.solve_sudoku(ctypes.cast(grid, ctypes.POINTER(ctypes.c_int)))

    if result:
        for row in grid:
            print(list(row))
    else:
        print("No solution")


if __name__ == "__main__":
    main()
