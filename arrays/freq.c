#include <stdio.h>
#include <string.h>

void countFreq(char*);
void countFreqHash(char*);

int main(){
	char str[255];
	printf("Enter string: ");
	scanf("%[^\n]s", str);

	countFreqHash(str);
	return 0;
}

void countFreq(char* str){
	int i, j, count, len = strlen(str);
	for(i=0; i<len; i++){
		if(str[i] == ' ') continue;
		count = 0;
		for(j=0; j<len; j++){
			if(str[i] == str[j]){
				if(j < i) break;
				else count++;
			}
		}

		if(count){
			printf("%c: %d\n", str[i], count);
		}
	}
}

void countFreqHash(char* str){
	int frequencies[128] = {0};
	int len = strlen(str), i;
	
	for(i=0; i<len; i++){
		if(str[i] == ' ') continue;
		frequencies[str[i]]++;
	}

	for(i=0; i<128; i++){
		if(frequencies[i] > 0){
			printf("%c---%d\n", i, frequencies[i]);
		}
	}
}
