#include <stdio.h>

int add(int,int);

int main(){
	int x, y;
	printf("Enter two integers: ");
	scanf("%d%d", &x, &y);

	int result = add(x, y);

	printf("Result = %d", result);
	return 0;
}

int add(int a, int b){
	int c;
	c = a + b;
	return c;
}
