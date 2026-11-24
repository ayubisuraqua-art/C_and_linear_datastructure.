#include <stdio.h>

void display(int mat[4][4], int rows, int cols){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%2d ", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

int main(){
	int mat[][4] = {{1,3,5,7},{2,4,6,8},{10,20,30,40},{11,22,33,44}};
	
	int rows = sizeof(mat)/sizeof(mat[0]);
	int cols = sizeof(mat[0])/sizeof(mat[0][0]);

	int temp, i, j;

	display(mat, rows, cols);

	for(i=0; i<rows; i++){
		for(j=0; j<i; j++){
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}

	display(mat, rows, cols);
	return 0;
}
