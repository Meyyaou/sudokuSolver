#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS=9;
int SIZE_COLS=9;

int main(){
	printf("hello");
	int ** puzzle;
	Sudoku * sudoku;
	int progress;
	
	puzzle=createPuzzle();
	sudoku= setUpPuzzle(puzzle);
	printPuzzle(sudoku->squares);
	//checkpuzzle while sudoku->squares[i]->possible==0
	while(UNSOLVED>0){
	    progress =checkPuzzle(sudoku->squares, sudoku->boxes);
	if (progress==0){
		printf("\nFailed to solve \n");
		break;
	}
	}
	printf("\nThe solution:\n");
    printPuzzle(sudoku->squares);
	return 0;
}
