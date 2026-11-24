#include <stdio.h>

void display(int arr[][3], int rows, int cols){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void display2(int arr[][2], int rows, int cols){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){

	int matA[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int matB[][3] = {{10,11,12}, {13,14,15}, {16,17,18}};

	int rows = sizeof(matA)/sizeof(matA[0]);
	int cols = rows;
	int i, j;

	printf("A:\n");
	display(matA, rows, cols);

	printf("\n");
	printf("B: \n");
	display(matB, rows, cols);

	/* Addition */
	int matC[3][3] = {{0}};

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}

	printf("Addition Result: \n");
	display(matC, rows, cols);
	
	/* Multiplication */
	int matX[][2] = {{1,3},{2,6},{10,20}};
	int matY[][3] = {{5,7,9}, {8,10,12}};
	int rowsX = sizeof(matX)/sizeof(matX[0]);
	int colsX = sizeof(matX[0])/sizeof(matX[0][0]);
	int rowsY = sizeof(matY)/sizeof(matY[0]);
	int colsY = sizeof(matY[0])/sizeof(matY[0][0]);	

	printf("\n\nX:\n");
	display2(matX, rowsX, colsX);

	printf("\n");
	printf("Y: \n");
	display(matY, rowsY, colsY);

	/* Multiplication */
	int matZ[3][3] = {{0}};

	for(i=0; i<rowsX; i++){
		for(j=0; j<colsY; j++){
			int k;
			for(k=0; k<colsX; k++){
				matZ[i][j] += matX[i][k] * matY[k][j]; 
			}
		}
	}

	printf("Multiplication: \n");
	display(matZ, 3, 3);

	return 0;
}
