#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

void createList(int);
void traverse();
void insertNode(int, int);
void deleteNode(int);

static Node* head = NULL;

int main(){
	int data, choice, pos;
	
	while(1){
		printf("1. Create List\n");
		printf("2. Traverse List\n");
		printf("3. Insert Node\n");
		printf("4. Delete Node\n");
		printf("5. Exit\n");
	
		printf("\nEnter choice (1-5): ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter no. of nodes: ");
				scanf("%d", &data);
				createList(data);
				break;

			case 2:
				traverse();
				break;
			
			case 3:
				printf("\nEnter position: "); scanf("%d", &pos);
				printf("\nEnter data: "); scanf("%d", &data);
				insertNode(data, pos);
				break;
			
			case 4:
				printf("\nEnter position: ");
				scanf("%d", &pos);
				deleteNode(pos);
				break;

			case 5:
				exit(0);

			default:
				printf("\nWrong Option!\n");
		}
	}

	return 0;
}

void deleteNode(int pos){
	if(head == NULL){
		printf("\nEmpty List!\n");
		return;
	}

	Node* p = head, *q = head;
	
	if(pos == 1){
		if(p->next == p){
			head = NULL;
			free(p);
		} else {
			while(q->next != head) q = q->next;
			
			q->next = p->next;
			p->next->prev = q;
			head = p->next;
			p->next = NULL;
			p->prev = NULL;
			free(p);
			
		}
	} else {
		int count = 1;
		
		while((p->next != head) && count < pos){
			p = p->next;
			count++;
		}

		if(count == pos){
			p->next->prev = p->prev;
			p->prev->next = p->next;
			p->next = NULL;
			p->prev = NULL;

			free(p);
		} else {
			printf("\nPosition does not exist!\n");
		}
	}
}

void insertNode(int data, int pos){
	Node* p = head, *temp;

	temp = (Node*)malloc(sizeof(Node));
	if(temp == NULL){
		printf("\nFailed to create node!\n");
		return;
	}

	temp->data = data;
	temp->next = temp;
	temp->prev = temp;

	if(head == NULL){
		head = temp;
		return;
	}

	if(pos == 1){
		while(p->next != head) p = p->next;

		temp->next = head;
		temp->prev = p;
		p->next = temp;
		head->prev = temp;
		head = temp;
	} else {
		int count = 1;

		while((p->next != head) && (count < pos - 1)){
			p = p->next;
			count++;
		}

		if(count == (pos-1)){
			temp->next = p->next;
			temp->prev = p;
			p->next->prev = temp;
			p->next = temp;

		} else {
			printf("\nPosition does not exist!\n");
			return;
		}
	}
}

void createList(int n){
	Node* p, *temp;
	int data;

	while(n > 0){
		temp = (Node*)malloc(sizeof(Node));
		printf("Enter data: ");
		scanf("%d", &temp->data);

		temp->next = temp;
		temp->prev = temp;

		if(head == NULL){
			head = temp;
			p = temp;
		} else {
			p->next = temp;
			temp->prev = p;
			temp->next = head;
			p = p->next;
			head->prev = temp;
		}

		n--;
	}
}

void traverse(){
	Node* temp = head;
	
	if(temp == NULL){
		printf("\nList is empty!\n\n");
		return;
	}
	
	printf("\nList (Forward): \n");

	do {
		printf("%d\t", temp->data);
		temp = temp->next;
	} while(temp != head);

	printf("\nList (Backward): \n");

	temp = temp->prev;

	do {
		printf("%d\t", temp->data);
		temp = temp->prev;
	} while(temp != head);

	printf("%d\t", temp->data);

	printf("\n\n");
}
