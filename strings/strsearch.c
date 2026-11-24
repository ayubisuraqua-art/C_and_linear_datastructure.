#include <stdio.h>
#include <string.h>

int naiveSearch(char*, char*);

int main(){
	char str[255] = "This is a sample paragraph, and will be used for searching text. I am at Lucknow Junction EAST";
	char pattern[255];

	printf("Enter string to search: ");
	scanf("%s", pattern);

	int idx = naiveSearch(str, pattern);
	if(idx != -1){
		printf("Present at index %d\n", idx);
	} else {
		printf("Pattern not present in the string!\n");
	}
}

int naiveSearch(char* str, char* pattern){
	int lens = strlen(str);
	int lenp = strlen(pattern);

	int i, j;
	for(i=0; i<=(lens-lenp); i++){
		if(str[i] == pattern[0]){
			for(j=1; j<lenp; j++){
				if(str[i+j] != pattern[j]) break;
			}

			if(j == lenp) return i;
		}
	}

	return -1;
}
