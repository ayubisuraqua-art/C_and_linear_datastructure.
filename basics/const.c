#include <stdio.h>

int main(){
	int y = 15;
	const int x = 10;

	int* p = &x;
	*p = 20;
	printf("x = %d\n", x);
	
	int* const q = &x;
	*q = 30;
	printf("x = %d\n", x);

	const int* r = &x;
	/**r = 40;*/
	printf("x = %d\n", x);

	const int* const s = &x;
	/* *s = 50; */
	printf("x = %d\n", x);

	return 0;
}
