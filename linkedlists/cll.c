#include <stdio.h>
#include <stdlib.h>

void createList(int);
void traverse();

typedef struct Node {
	int data;
	struct Node* next;
} Node;

static Node* head = NULL;

int main(){
	int choice, data;
	
	while(1){
		printf("1. Create List\n");
		printf("2. Traverse\n");
		printf("3. Exit\n");

		printf("\nEnter Choice(1-3): ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter no. of nodes to create: ");
				scanf("%d", &data);
				createList(data);
				break;

			case 2:
				traverse();
				break;

			case 3:
				exit(0);

			default:
				printf("\nWrong choice!\n");
		}	
	}

	return 0;
}


void createList(int n){
	int i = 0;
	Node* temp, *p = head;

	while(i < n){
		temp = (Node*)malloc(sizeof(Node));
		
		if(temp == NULL){
			printf("Failed to create list!\n");
			exit(0);
		}

		temp->next = NULL;
		printf("Enter data for Node %d: ", i + 1);
		scanf("%d", &temp->data);

		if(p == NULL){
			p = temp;
			head = temp;
			p->next = p;
		} else {
			temp->next = head;
			p->next = temp;
			p = p->next;
		}

		i++;
	}
}

void traverse(){
	Node* p = head;
	
	printf("\nList: \n");
	if(p != NULL){
		do {
			printf("%d\t", p->data);
			p = p->next;
		} while(p != head && p != NULL);
	}

	printf("\n\n");
}
