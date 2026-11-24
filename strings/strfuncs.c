#include <stdio.h>
#include <string.h>

int main(){
	char* s1 = "Lucknow Junction EAST";
	char* s2 = "unct";
	
	char* res = strstr(s1, s2);
	if(res != NULL){
		printf("%s\n", res);
	} else {
		printf("Not found\n");
	}
		
	return 0;
}
