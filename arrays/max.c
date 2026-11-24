#include <stdio.h>

int max(int a, int b){
	return (a>b) ? a : b;
}


int maxSubArray(int* a, int len){
	int sum = 0;
	int bestSum = 0;
	int i;
	for(i=0; i<len; i++){
		sum = max(a[i], sum+a[i]);
		bestSum = max(bestSum, sum);
	}

	return bestSum;
}	

int main(){
	int arr[] = {2,-3,4,2,-3,7,1,-4};
	
	int len = sizeof(arr)/sizeof(arr[0]);

	printf("%d\n", maxSubArray(arr, len));
	return 0;
}
