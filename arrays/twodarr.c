#include <stdio.h>

int main(){
	int arr[][5] = {{1,3,5,7,9}, {2,4,6,8,10}, {11,22,33,44,55}};

	int rows = sizeof(arr) / sizeof(arr[0]);
	int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

	int i, j;
	
	for(i=0; i<rows; i++){
		for(j=0;j<cols; j++){
			printf("%d ", i[arr][j]);
		}

		printf("\n");
	}

	
	return 0;
}
