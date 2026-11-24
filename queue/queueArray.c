#include <stdio.h>

#define N 5

static int queue[N] = {0};
static int front = -1;
static int rear = -1;

void enqueue(int data){
	if(rear == N - 1){
		printf("Overflow: Queue is full!\n");
		return;
	}

	queue[++rear] = data;
	if(rear == 0) front = 0;
}

int dequeue(){
	if((front == -1) && (rear == -1)){
		printf("Underflow: Queue is empty!\n");
		return -1;
	}

	int data = queue[front++];
	if(front > rear){
		front = -1;
		rear = -1;
	}

	return data;
}
