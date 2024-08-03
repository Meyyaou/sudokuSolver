#include "sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes){
	int i,k,j;
	int sums[9];
	int pos[9];
	//loop through all rows
	for (i=0; i<9; i++){
		for (j=0;j<9; j++){//init sums and position of solution to find
			pos[j]=0;
			sums[j]=0;
		}
		//loop through each square in a row
		for (j=0; j<9; j++){
			if(sudoku[i][j]->value!=0)
				continue;
			//loop through each possible 
			for (k=0; k<9; k++){
				if (sudoku[i][j]->possible[k]==0){//it is indeed ppossible
					sums[k]++;
					pos[k]=j;
				}
			}
		}
		for(k=0;k<9;k++){
			if(sums[k]==1){
				//you can solve it
				sudoku[i][pos[k]]->value=k+1;
				sudoku[i][pos[k]]->solvable=0;
				UNSOLVED--;
				updateSudoku(sudoku, i ,pos[k]);
				updateBoxes(sudoku, i ,pos[k]);
				return 1;
			}
			}
		}
	
	return 0;//in case of failure
}
