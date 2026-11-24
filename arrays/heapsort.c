#include <stdio.h>

#define LEFT(i) (2 * (i))
#define RIGHT(i) (2*(i) + 1)

void build_max_heap(int* arr, int n){
	int i = n/2;
	
	for(;i>=0; i--){
		max_heapify(arr, n, i);
	}
}

void max_heapify(int* arr, int heap_size, int i){
	int left = LEFT(i);
	int right = RIGHT(i);
	
	int largest;
	if(left < heap_size && arr[left] > arr[right])
		largest = left;
	else largest = i
	
	if(right < heap_size && arr[right] > arr[largest])
		largest = right;
	
	if(largest != i){
		/* Swap parent with largest */
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		max_heapify(arr, heap_size, largest);
	}
}

void heap_sort(int* arr, int n){
	build_max_heap(arr, n);
	
	int i, temp;
	for(i=n; i>2; i--){
		temp = arr[i];
		arr[i] = arr[n-1];
		arr[n-1] = temp;
		max_heapify(arr, n, );
	}
}

int main(){
	int arr[] = {4,3,1,9,0,2,5,7,8,6};
	int n = sizeof(arr) / sizeof(arr[0]);

	heap_sort(arr, n);
	
	/* Display */
	int i;
	for(i=0; i<n; i++){
		printf("%d\t", arr[i]);
	}

	printf("\n");
	return 0;
}
