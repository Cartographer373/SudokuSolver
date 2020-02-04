#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <set>
#include <fstream>

using namespace std;

typedef vector<vector<int>> grid;

vector<int> listAllRelatedSquares(grid puzzle, int x, int y){
	/* List all values that are releted to the given square*/
	set<int> usedNumbers;
	for(int i=0; i<9; i++){
		usedNumbers.insert(puzzle[x][i]);
		usedNumbers.insert(puzzle[i][y]);
	}
}

vector<int> stringToIntHelper(string input, bool& solution){
	vector<int> intReturnValues;
	bool 
	for(int i=0; i<input.length(); i++){
		if(input[i]=='.'){
			solution = false
			intReturnValues.push_back(0);
		}else{
			intReturnValues.push_back('0'-input[i]);
		}
	}
}

vector<vector<int>> oneDemToTwoDemHelper(vector<int> 


bool importSudokus(std::string path){
	/* Function for importing sudokus from a file.
		uses 81 char lines of either . or [1..9] to denote
		a Puzzle followed by an 81 char solution.
	*/
	vector<string> puzzles;
	string line;
	ifstream puzzleFile(path);
	
	if(puzzleFile.is_open()){
		while(getline(puzzleFile, line)){
			//convert string line to int line with 0 replacing .
			//seperate lines into rows and col
			bool solution = true;
			vector<vector<int>> sudoNumbers = oneDemToTwoDemHelper(
				stringToIntHelper(line, solution)
			)
			//add to puzzle list(switch depending on if its a solution or not)
			if(solution){
				solutions.push_back(sudoNumbers);
			}else{
				puzzles.push_back(sudoNumbers);
			}
		}
	}

}

vector<int> listPossibleValues(grid puzzle, int dist){
	// Return a list of all possible values for a square.
}



int main(){

}
