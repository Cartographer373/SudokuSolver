.PHONEY: all clean debug

all: debug

sudokuSolver: solver.cpp
	g++ --std=c++11 solver.cpp -o sudokuSolver

debug: solver.cpp
	g++ --std=c++11 -g solver.cpp
