#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

//future definitons
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

typedef struct Sudoku{
	struct Square *** squares;
	struct Box ** boxes;	
}Sudoku;

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
Sudoku * setUpPuzzle(int ** puzzle);
Sudoku * createSudoku(Square *** squares, Box ** boxes);
void printPuzzle(Square *** puzzle);

int checkPuzzle(Square *** sudoku, Box ** boxes);
int updateSudoku(Square *** sudoku, int row, int col);

int solveSquare(Square * square);

Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int col);
int boxSingles(Square *** sudoku,Box ** boxes);
#endif
