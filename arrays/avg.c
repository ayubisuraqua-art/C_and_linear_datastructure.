#include <stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){
	if(argc == 1){
		printf("Correct usage: <cmd> <args...>\n");
		return 1;
	}

	float sum = 0.0f;
	int i;

	for(i=1; i<argc; i++){
		sum += atof(argv[i]);
	}
	printf("%f\n",sum);
	float avg = (float)sum / (argc - 1);
	printf("Average: %f\n", avg);
	
	return 0;
}
