#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int data, choice;
	while(1){
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");

		printf("\nEnter your choice(1-3): ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter data: "); scanf("%d", &data);
				enqueue(data);
				break;

			case 2:
				data = dequeue();
				if(data != -1){
					printf("\nRemoved -> %d\n", data);
				}
				break;

			case 3:
				exit(0);
	
			default:
				printf("\nWrong option!\n");
		}
	}

	return 0;
}
