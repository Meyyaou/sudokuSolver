#include "sudoku.h"

//to store the values from the puzzle
Square *** setUpPuzzle(int ** puzzle){
	Square *** sudoku;
	int i, j, x;
	sudoku= (Square***)malloc(sizeof(Square**)*9);
	//loop through rows
	for (i = 0; i<SIZE_ROWS; i++){
		sudoku[i]= (Square**)malloc(sizeof(Square*)*9);
		
		//loop through cols
		for (j = 0; j <SIZE_COLS;j++){
			sudoku[i][j]= (Square*)malloc(sizeof(Square)*9);
			sudoku[i][j]->value=puzzle[i][j];
			
			//assign rows and cols
			sudoku[i][j]->row=i;
			sudoku[i][j]->col=j;
			sudoku[i][j]->solvable=9;
			
			for (x=0; x<SIZE_ROWS; x++){
				sudoku[i][j]->possible[x]=0;
				
			}
		}
	}
	
		//loop through rows
		for (i = 0; i<SIZE_ROWS; i++){
		
		//loop through cols
		for (j = 0; j <SIZE_COLS;j++){
			//if no val 
		if (sudoku[i][j]->value!=0){
			sudoku[i][j]-> solvable= 0;
			updateSudoku(sudoku, i,j );
			UNSOLVED--;
		}
		}
}
return sudoku;
}



int updateSudoku(Square *** sudoku, int row, int col){
	int x;
	int num=sudoku[row][col]->value;
	
	//verif par rapport aux cols
	for(x=0; x<SIZE_ROWS; x++){
		if(sudoku[x][col]->possible[num-1]==0) {
			sudoku[x][col]->solvable--;
		}
		sudoku[x][col]->possible[num -1]=1;
	}
	//verif par rapport aux rows
		for(x=0; x<SIZE_COLS; x++){
		if(sudoku[row][x]->possible[num-1]==0) {
			sudoku[row][x]->solvable--;
		}
		sudoku[row][x]->possible[num -1]=1;
	}
	return 1;
	
}


int checkPuzzle(Square *** sudoku){
	int i, j;
	
	//loop through rows
	for (i = 0; i<SIZE_ROWS; i++){
		
		//loop through cols
		for (j = 0; j <SIZE_COLS;j++){
		if (sudoku[i][j]->solvable==1){
			solveSquare(sudoku[i][j]);
			updateSudoku(sudoku, i, j);
		}
		}
		
		}
		return 1;
}

int ** createPuzzle(){
	int ** puzzle;
	int i,j;
	int array[9][9]={0, 1, 9,	 0, 0, 2,	 0, 0, 0,
					 4, 7, 0,	 6, 9, 0,	 0, 0, 1,
					 0, 0, 0,	 4, 0, 0,	 0, 9, 0,
					
					 8, 9, 4,	 5, 0, 7,	 0, 0, 0,
					 0, 0, 0,	 0, 0, 0,	 0, 0, 0,
					 0, 0, 0,	 2, 0, 1,	 9, 5, 8,
					
					 0, 5, 0,	 0, 0, 6,	 0, 0, 0,
					 6, 0, 0,	 0, 2, 8,	 0, 7, 9,
					 0, 0, 0,	 1, 0, 0,	 8, 6, 0
					};
	
	puzzle = (int**)malloc(sizeof(int*)*9);
	
	for (i = 0; i<SIZE_ROWS; i++){
		puzzle[i]=(int*)malloc(sizeof(int)*9);
		
		for (j = 0; j <SIZE_COLS;j++){
			puzzle[i][j]=array[i][j];
		}
	}
	return puzzle;
}


void printPuzzle(Square *** puzzle){
	int i,j;
	printf("-------------------------------\n");
	for (i=0; i<SIZE_ROWS; i++){
		//print rows
		for (j=0; j<SIZE_COLS; j++){
			if (j==0){
				printf("|");
			}
			/*if (puzzle[i][j]->value==0){
				printf(" %c ", '.');
			}else{}*/
			printf(" %d ", puzzle[i][j]->value);
			if ((j+1)%3==0){
				printf("|");
			}
		}
		printf("\n");
		if ((i+1)%3==0){
			printf("------------------------------\n");

		}
	}
}
