#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("Correct Usage: <executable> <fileName>\n");
		return 1;
	}

	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("Failed to open the file!\n");
		return 1;
	}

	int data;
	while((data = getc(fp)) != -1){
		putchar(data);
	}

	fclose(fp);
	return 0;
}	
