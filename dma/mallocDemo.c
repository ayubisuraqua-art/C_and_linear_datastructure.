#include <stdio.h>
#include <stdlib.h>

int main(){
	int*k = (int*)malloc(10000*sizeof(int));
	int i;
	for(i=0; i<10000; i++) k[i] = i*i;
	free(k);

	int* p = (int*)malloc(5*sizeof(int));
	
	/*for(i=0; i<5; i++) p[i] = i*i;*/

	for(i=0; i<5; i++) printf("%d\t", p[i]);

	printf("\n");

	return 0;
}
