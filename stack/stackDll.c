#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

static Node* top = NULL;

void push(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	
	if(temp == NULL){
		printf("\nStackOverflow: Failed to insert Node!\n");
		return;
	}

	temp->data = data;
	temp->next = NULL;
	temp->prev = top;

	if(top != NULL)
		top->next = temp;
	else
		top = temp;

	top = temp;
}

int pop(){
	if(top == NULL){
		printf("\nStackUnderflow: Stack is empty!\n");
		return -1;
	}

	Node* p = top;
	top = p->prev;

	if(top != NULL) top->next = NULL;

	p->prev = NULL;

	int data = p->data;
	free(p);

	return data;
}

int main(){
	int data, choice;

	while(1){
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &data);
				push(data);
				break;

			case 2:
				data = pop();
				if(data != -1){
					printf("\nPopped -> %d\n\n", data);
				}
				break;

			case 3:
				exit(0);

			default:
				printf("\nWrong Option!\n");
		
		}
	}

	return 0;
}
