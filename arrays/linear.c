#include <stdio.h>

int main(){
	int arr[] = {3,4,5,7,18,9,6};

	int len = sizeof(arr)/sizeof(arr[0]);
	int i;

	int data;
	printf("Enter number to search: ");
	scanf("%d", &data);

	for(i=0; i<len; i++){
		if(arr[i] == data){
			printf("%d found at index %d\n", data, i);
			return 0;
		}
	}

	printf("%d not found!\n", data);
	return 0;
}
