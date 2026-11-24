#include <stdio.h>
#include <string.h>

int main(){
	char name[] = "Amit Kumar";
	
	printf("Original: %s\n", name);

	int i;
	for(i=0; i<strlen(name); i++){
		if(name[i] >= 65 && name[i] <= 90){
			/*name[i] = (char)(name[i] ^ 32);*/
			name[i] = name[i] + 32;
		}
	}

	printf("Lowercase: %s\n", name);
	return 0;
}
