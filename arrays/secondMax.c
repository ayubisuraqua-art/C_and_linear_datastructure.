#include <stdio.h>

int main(){
	int arr[] = {3,7,5,4,18,9,2,6};
	
	int max = arr[0], smax = arr[0];
	int i;
	int len = sizeof(arr) / sizeof(arr[0]);

	for(i=1; i<len; i++){
		if(max < arr[i]){
			smax = max;
			max = arr[i];
		} else if(smax < arr[i]){
			smax = arr[i];
		}
	}

	printf("max = %d\tsecond max = %d\n", max, smax);
	return 0;
}
