#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

static Node* front = NULL;
static Node* rear = NULL;

/* Functions */
void enqueue(int);
int dequeue();

int main(){
	int data, choice;

	while(1){
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &data);
				enqueue(data);
				break;

			case 2:
				data = dequeue();
				if(data != -1) printf("\nRemoved -> %d\n", data);
				break;

			case 3:
				exit(0);
		
			default:
				printf("\nWrong Option!");
		}
	}

	return 0;
}

void enqueue(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	if(temp == NULL){
		printf("\nFailed to create Node!\n");
		return;
	}

	temp->data = data;
	temp->prev = rear;
	temp->next = NULL;
	
	if(rear != NULL) rear->next = temp;

	rear = temp;

	if(front == NULL) front = temp;
}

int dequeue(){
	Node* p = front;
	int data;
	
	if(front == NULL){
		printf("\nQueue Empty!\n");
		return -1;
	}

	front = front->next;
	if(front == NULL) rear = NULL;
	else {
		front->prev = NULL;
	}

	p->next = NULL;
	p->prev = NULL;
	
	data = p->data;
	free(p);

	return data;
}
