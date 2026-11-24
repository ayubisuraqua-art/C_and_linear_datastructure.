#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int data, choice;
	
	while(1){
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n\n");
		
		printf("Enter your choice(1-3): ");	scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter data:");
				scanf("%d", &data);
				push(data);
				break;
			
			case 2:
				data = pop();
				if(data != -1) {
					printf("\nPopped -> %d\n\n", data);
				}

				break;

			case 3:
				exit(0);
			
			default:
				printf("\nWrong choice!\n\n");
		
		}
	}

	return 0;
}
