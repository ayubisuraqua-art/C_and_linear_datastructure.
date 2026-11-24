#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

static struct Node *top = NULL;

void push(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if(temp == NULL){
		printf("StackOverflow: Stack is full\n");
		return;
	}

	temp->data = data;
	temp->next = top;
	top = temp;
}

int pop(){
	if(top == NULL){
		printf("StackUnderflow: Stack is empty!\n");
		return -1;
	}

	int x = top->data;
	struct Node* temp = top;

	top = top->next;
	temp->next = NULL;
	free(temp);

	return x;	
}
