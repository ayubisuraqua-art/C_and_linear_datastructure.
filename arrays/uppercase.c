#include <stdio.h>
#include <string.h>

int main(){
	char name[] = "Amit Kumar";
	
	printf("Original: %s\n", name);
	int i;
	for(i=0; i<strlen(name); i++){
		if(name[i] >= 97 && name[i] <= 122){
			name[i] = (char)(name[i] ^ 32);
		}
	}

	printf("Uppercase: %s\n", name);
	return 0;
}
