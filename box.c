#include "sudoku.h"

Box ** createBoxes(){
	
	Box ** boxes;
	int x,y;
	
	boxes = (Box **)malloc(sizeof(Box*)*9);
	for (x= 0; x<9; x++){
		boxes[x]=(Box *)malloc(sizeof(Box));
		boxes[x]->squares=(Square **)malloc(sizeof(Square*)*9);
		boxes[x]->nums= 0;
		boxes[x]->solvable=9;
	for (y=0; y<9; y++){
		boxes[x]->possible[y]=0;
	}
	}
	return boxes;
}

int updateBoxes(Square *** sudoku, int row, int col){
	int x;
	int num =sudoku[row][col]->value;
	Box * box;
	box=sudoku[row][col]->box;
	
	for (x=0; x<9; x++){
		if (box->squares[x]->possible[num-1]==0){//means it's solvable
			box->squares[x]->solvable--;
			box->squares[x]->possible[num-1]=1;
		}
	}
}
