#include <stdio.h>

struct student {
	char* name;
	int age;
	char gender;
} stu = {"Manoj", 12, 'M'};

int main(int argc, char** argv){
	/*struct student stu;
	stu.name = "Manoj";
	stu.age = 12;
	stu.gender = 'M';*/

	printf("Name: %s\n", stu.name);
	printf("Age: %d\n", stu.age);
	printf("Gender: %c\n", stu.gender);
	printf("%d\n", sizeof(stu));	
	return 0;
}
