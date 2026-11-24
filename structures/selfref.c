#include <stdio.h>

struct student {
	char* name;
	int age;
	struct student* sp;
};

int main(){
	struct student first;
	struct student second;
	struct student* head;

	first.name = "Amit";
	first.age = 20;
	first.sp = &second;

	second.name = "Sumit";
	second.age = 30;

	head = &first;

	printf("First Age: %d\nSecond Age: %d\n", head->age, head->sp->age);
	return 0;
}
