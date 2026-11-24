#include <stdio.h>

int main(){
	int age = 10;
	int* y;
	y = &age;
	int k = &age;
	printf("Address of age = %p, Address of age = %x\n", y, k);
	y++; k++;
	printf("Address of age = %p, Address of age = %x\n", y, k);
	
	return 0;
}
