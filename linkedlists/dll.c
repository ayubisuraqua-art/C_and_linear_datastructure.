#include <stdio.h>
#include <stdlib.h>

void create(int);
void traverse();
void insert(int);
void deleteNode(int);

struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
}* head = NULL;

int main(int argc, char** argv){
	int choice, n, position;

	while(1){
		printf("1. Create\n");
		printf("2. Traverse\n");
		printf("3. Insert at N\n");
		printf("4. Delete a Node\n");
		printf("5. Exit\n");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter no. of nodes to insert: ");
				scanf("%d", &n);
				create(n);
				break;

			case 2:
				printf("\nList: \n");
				traverse();
				break;

			case 3:
				printf("\nEnter position: ");
				scanf("%d", &position);
				insert(position);
				break;
			
			case 4:
				printf("\nEnter position: ");
				scanf("%d", &position);
				deleteNode(position);
				break;

			case 5:
				exit(0);
	
			default:
				printf("Wrong choice!\n");
		}
	}

	return 0;
}

void deleteNode(int pos){
	struct Node* p = head;
	int i = 1;

	if(p == NULL){
		printf("\nEmpty List!\n");
		return;
	} else if(pos == 1){
		head = p->next;
		p->next->prev = NULL;
	} else {
		while(i < pos){
			p = p->next;
			i++;
		}

		if(i != pos){
			printf("\nPosition doesn't exist!\n");
		}
		
		p->prev->next = p->next;
		if(p->next) p->next->prev = p->prev;
	}
	
	p->next = NULL;
	p->prev = NULL;
	free(p);
}

void create(int n){
	struct Node* temp, *p;
	int data, i;

	for(i=1; i<=n; i++){
		temp = (struct Node*)malloc(sizeof(struct Node));

		if(temp == NULL){
			printf("\nCould not create list!\n");
			return;
		}

		printf("Enter data: ");
		scanf("%d", &temp->data);
		
		if(head == NULL){
			head = temp;
		} else {
			p = head;
			while(p->next != NULL) p = p->next;

			p->next = temp;
			temp->prev = p;
		}
		
	}
}

void traverse(){
	struct Node* p = head;
	
	printf("Forward: ");
	while(p->next != NULL){
		printf("%d -> ", p->data);
		p = p->next;
	}

	printf("%d\n", p->data);
	printf("\nBackward:\n");
	while(p->prev != NULL){
		printf("%d -> ", p->data);
		p = p->prev;
	}

	printf("%d\n\n", p->data);
}

void insert(int pos){
	struct Node* temp, *p;
	int i;

	temp = (struct Node*)malloc(sizeof(struct Node));

	if(temp == NULL){
		printf("Could not create node!\n");
		return;
	}

	temp->next = NULL;
	temp->prev = NULL;
	
	i = 1;
	p = head;
	while(i<pos && p != NULL && p->next != NULL){
		p = p->next;
		i++;
	}

	if(i == pos){
		printf("Enter data: ");
		scanf("%d", &temp->data);
		
		temp->next = p;
		temp->prev = p->prev;

		if(pos != 1) temp->prev->next = temp;
		else head = temp;

		p->prev = temp;
		
	} else {
		printf("Position doesn't exist!\n");
	}
}
