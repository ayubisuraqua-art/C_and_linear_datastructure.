#include <stdio.h>
#include <string.h>

void reverse(char* str){
	int i = 0, j = strlen(str)-1, temp;

	while(i<j){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int main(){
	char name[] = "Lucknow";
	printf("Original: %s\n", name);

	reverse(&name[0]);
	printf("Reversed: %s\n", name);

	return 0;
}
