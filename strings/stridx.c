#include <stdio.h>
#include <string.h>

char* addrOf(char*, char ch);
int indexOf(char*, char ch);

int main(){
	char name[] = "Lucknow Junction";
	printf("Index of k: %d\n", indexOf(name, 'k'));
	printf("Index of z: %d\n", indexOf(name, 'z'));

	printf("Address of J: %p (%c)\n", addrOf(name, 'J'), 'J');
	printf("Address of Z: %p (%c)\n", addrOf(name, 'Z'), 'Z');

	return 0;
}

char* addrOf(char* str, char ch){
	while(*str != '\0'){
		if(*str == ch) return str;
		str++;
	}

	return NULL;
}

int indexOf(char* str, char ch){
	int i;
	for(i=0; i<strlen(str); i++){
		if(str[i] == ch) return i;
	}

	return -1;
}
