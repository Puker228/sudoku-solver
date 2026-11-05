# sudoku-solver

A simple library for solving 9x9 Sudoku puzzles

## Compile

```shell
cmake -B build
cmake --build build
```

## Python example

The example in [`examples/python/main.py`](examples/python/main.py) uses
`ctypes` to call `solve_sudoku` from the shared library. After compiling the
library on macOS, copy it next to the script and run the example:

```shell
cp build/libsudoku.dylib examples/python/
cd examples/python
python3 main.py
```

On Linux or Windows, use `libsudoku.so` or `sudoku.dll` respectively and update
the library path in `main.py`.

## Go example

The example in [`examples/go/main.go`](examples/go/main.go) uses cgo to call
`solve_sudoku` from the shared library. After compiling the library, run it from
the repository root:

```shell
go run examples/go/main.go
```

CGO must be enabled, and a C compiler must be available.
