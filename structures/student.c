#include <stdio.h>

typedef struct {
	char* name;
	int age;
	char gender;
} student;

student* sp;
student stu;

int main(int argc, char** argv){
	sp = &stu;
	stu.name = "Manoj";
	sp->age = 10;
	stu.gender = 'M';

	printf("Name: %s\n", sp->name);
	printf("Age: %d\n", sp->age);
	printf("Gender: %c\n", sp->gender);

	return 0;
}
