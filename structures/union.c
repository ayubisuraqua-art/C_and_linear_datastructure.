#include <stdio.h>

union gender {
	int male;
	int female;
};

int main(int argc, char* argv[]){
	union gender bird;
	bird.male = 1;	
	

	printf("%d\n", (int)sizeof(bird));
	printf("%d\n", bird.male);
	printf("%d\n", bird.female);

	return 0;
}
