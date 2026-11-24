#include <stdio.h>

int main(){
	int arr[] = {1,2,3,4,5,6,7,8};
	
	int* p = &arr[0];
	int len = sizeof(arr)/sizeof(arr[0]);

	int i;
	for(i=0; i<len; i++){
		printf("%d\t", p[i]);
	}

	printf("\n");

	return 0;
}
