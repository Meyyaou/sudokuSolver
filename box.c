#include "sudoku.h"
int boxSingles(Square *** sudoku,Box ** boxes){
	int i, k,j,c,pos;
	
	//loop through boxes
	for (i=0; i<9; i++){
		//loop through possible array
		for (j=0; j<9; j++){
			c=0;
			//loop through squares
			for (k=0; k<9; k++){
				if(boxes[i]->squares[k]->value!=0)
					continue;
				if(boxes[i]->squares[k]->possible[j]==0){
					c++;
					pos=k;
			}
				if(c==2)
					break;
				
			}
			if (c==1){//definitely solvable (1 solution)
				boxes[i]->squares[pos]->value=j+1;
				UNSOLVED--;
				boxes[i]->squares[pos]->solvable=0;
				updateSudoku(sudoku,boxes[i]->squares[pos]->row ,boxes[i]->squares[pos]->col );
			return 1;
			}
			
		}
	}
	return 0;
}
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


