#include <stdio.h>

long fact(unsigned int n){
	/*if(n == 1 || n == 0){
		return 1;
	}

	return n*fact(n-1);*/

	long result = 1;
	for(int i=n; i>1; i--){
		result *= i;
	}

	return result;
}

int main(){
	unsigned int n;
	printf("Enter a number: ");
	scanf("%ud", &n);

	long factorial = fact(n);
	
	printf("Factorial of %u is %ld\n", n, factorial);

	return 0;
}
