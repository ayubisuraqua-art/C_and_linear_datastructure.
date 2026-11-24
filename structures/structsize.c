#include <stdio.h>

struct student {
	char name;
	int age;
};

int main(){
	printf("%u\n", sizeof(struct student));
	return 0;
}
