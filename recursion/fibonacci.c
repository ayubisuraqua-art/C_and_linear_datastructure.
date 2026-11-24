#include <stdio.h>

long fib(int n){
	/*if(n == 1 || n == 2) return 1;
	else return fib(n - 1) + fib(n-2);*/

	long first = 1;
	long second = 1;
	long third = 1;

	int i;
	for(i = 3; i<=n; i++){
		third = first + second;
		first = second;
		second = third;
	}

	return third;
}

int main(){
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		printf("%ld ", fib(i));
	}
	printf("\n");
	return 0;
}	
