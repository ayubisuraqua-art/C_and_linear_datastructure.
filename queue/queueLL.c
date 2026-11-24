#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

static struct Node* front = NULL;
static struct Node* rear = NULL;

void enqueue(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	if(temp == NULL){
		printf("Overflow: Queue is full!\n");
		return;
	}

	temp->data = data;
	temp->next = NULL;

	if(rear == NULL && front == NULL){
		front = temp;
		rear = temp;
	} else {
		rear->next = temp;
		rear = temp;
	}
}

int dequeue(){
	struct Node* temp = front;
	
	if(front == NULL && rear == NULL){
		printf("Underflow: Queue is empty!\n");
		return -1;
	}
	
	int data = temp->data;
	front = front->next;

	if(front == NULL){
		rear = NULL;
	}

	free(temp);

	return data;
}
