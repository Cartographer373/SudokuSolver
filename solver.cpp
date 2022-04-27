#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <set>
#include <fstream>
#include <unordered_map>

using namespace std;

typedef vector<vector<int>> grid;

vector<int> stringToIntHelper(string input){
	vector<int> intReturnValues;
	for(int i=0; i<input.length(); i++){
		if(input[i]=='.'){
			intReturnValues.push_back(0);
		}else{
			intReturnValues.push_back(input[i]-'0');
		}
	}
    return intReturnValues;
}

void printSudoku(grid puzzle){
    for(int i=0; i<puzzle.size(); i++){
        for(int j=0; j<puzzle[0].size(); j++){
            std::cout<<puzzle[i][j];
        }
        std::cout<<std::endl;
    }
    cout<<endl;
}

bool importSudokus(std::string path, grid& P){
	/* Function for importing sudokus from a file.
		uses 81 char lines of either . or [1..9] to denote
		a Puzzle followed by an 81 char solution.
	*/
	vector<string> puzzles;
	string line;
	ifstream puzzleFile(path);
	
	if(puzzleFile.is_open()){
		while(getline(puzzleFile, line)){
            if(line=="Puzzle,Solution,"){
                continue;
            }
			//convert string line to int line with 0 replacing .
			vector<int> sudoNumbers = stringToIntHelper(line);
            for(int i=0; i<9*9; i++){
                P[i/9][i%9]=sudoNumbers[i];
            }
            return true;
		}
	}
    return false;
}
/*
vector<int> listPossibleValues(grid puzzle, int dist){
	// Return a list of all possible values for a square.
}
*/

bool isSafe(grid puzzle){
     // Hashmap for row column and boxes
    unordered_map<int, int> row_[9], column_[9], box[3][3];
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if(puzzle[row][col]==0){
                continue;
            }
            row_[row][puzzle[row][col]] += 1;
            column_[col][puzzle[row][col]] += 1;
            box[row/3][col/3][puzzle[row][col]] += 1;
            // if an element is already
            // present in the hashmap
            if (box[row/3][col/3][puzzle[row][col]]>1 || column_[col][puzzle[row][col]]>1 || row_[row][puzzle[row][col]]>1){
                //The puzzle is incomplete
                return false;
            }
        }
    }
    return true;
}

bool isComplete(grid puzzle){
     // Hashmap for row column and boxes
    unordered_map<int, int> row_[9], column_[9], box[3][3];
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            row_[row][puzzle[row][col]] += 1;
            column_[col][puzzle[row][col]] += 1;
            box[row/3][col/3][puzzle[row][col]] += 1;
            // if an element is already
            // present in the hashmap
            if ( box[row / 3][col / 3][puzzle[row][col]] > 1 || column_[col][puzzle[row][col]] > 1 || row_[row][puzzle[row][col]] > 1)
                //The puzzle is incomplete
                return false;
        }
    }
    return true;
}

bool bruteForcePuzzle(grid& puzzle, int row, int column){
    if(column==9 && row==8){
        return isComplete(puzzle);
    }
    if(column==9){
        column=0;
        row++;
    }
    if(puzzle[row][column]!=0){
        return bruteForcePuzzle(puzzle, row, column+1);
    }
    for(int guess=1; guess<10; guess++){
        puzzle[row][column]=guess;
        if(isSafe(puzzle) && bruteForcePuzzle(puzzle, row, column+1)){
            return true;
        }
        puzzle[row][column]=0;
    }
    return false;
}

bool bruteForcePuzzle(grid& puzzle){
    return bruteForcePuzzle(puzzle, 0, 0);
}

int main(int argc, char** argv){
    /* import and print a Sudoku */
    grid puzzle=vector<vector<int>>(9, vector<int>(9));
    if(importSudokus(argv[1], puzzle)){
        if(bruteForcePuzzle(puzzle)){
            printSudoku(puzzle);
            return 0;
        }
        cout<<"Couldn't Solve Puzzle"<<endl;
        return 1;
    }else{
        cout<<"Couldn't Import Puzzle"<<endl;
    }
}
