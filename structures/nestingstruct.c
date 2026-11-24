#include <stdio.h>

struct student {
	char* name;
	struct address {
		char* city;
		int pin;
	}* p;
};

int main(int argc, char* argv[]){
	struct student stu;
	printf("Size: %d\n", (int)sizeof(stu));
	
	stu.name = "Amit Kumar";
	stu.p->city = "Lucknow";
	stu.p->pin = 226026;

	printf("Name: %s\nCity: %s\nPin: %d\n", stu.name, stu.p->city, stu.p->pin);
	return 0;
}
