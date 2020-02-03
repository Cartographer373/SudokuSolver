#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <set>
#include <fstream>

typedef vector<vector<int>> grid;

vector<int> listAllRelatedSquares(grid puzzle, int x, int y){
	/* List all values that are releted to the given square*/
	set<int> usedNumbers;
	for(int i=0; i<9; i++){
		usedNumbers.insert(puzzle[x][i])
		usedNumbers.insert(puzzle[i][y])
	}
}

bool importSudokus(std::string path, grid puzzle, grid solution){
	/* Function for importing sudokus from a file.
		uses 81 char lines of either . or [1..9] to denote
		a Puzzle followed by an 81 char solution.
	*/
	ifstream puzzleList;
	
}

vector<int> listPossibleValues(grid puzzle, int dist){
	// Return a list of all possible values for a square.
}



int main(){

}