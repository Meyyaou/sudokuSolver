#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS=9;
int SIZE_COLS=9;

int main(){
	printf("hello");
	int ** puzzle;
	Square *** sudoku;
	
	puzzle=createPuzzle();
	sudoku= setUpPuzzle(puzzle);
	printPuzzle(sudoku);
	checkPuzzle(sudoku);
/*  checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);*/
	printf("\nThe solution:\n");
    printPuzzle(sudoku);
	return 0;
}
