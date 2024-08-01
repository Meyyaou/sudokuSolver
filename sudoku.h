#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

//future definitons
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

typedef struct Box{
	struct Square ** squares;
	int nums;
	int possible[9];
	int solvable;
	struct Box * next;
}Box;
typedef struct Square
{
	int value;
	//[0][0][0][0][1][0][1][0][0] bit nums par rapport aux possibilites: if 1=impo, 0=pos
	//[9][8][7][6][5][4][3][2][1] indexes 
	int possible[9];
	int solvable;
	Box * box;
	int row;
	int col;
} Square;

int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Square *** setUpPuzzle(int ** puzzle);

int checkPuzzle(Square *** sudoku);
int updateSudoku(Square *** sudoku, int row, int col);

int solveSquare(Square * square);

Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int col);

#endif
