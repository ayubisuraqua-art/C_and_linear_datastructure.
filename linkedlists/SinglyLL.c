#include <stdio.h>
#include <stdlib.h>

void createList(int);
void traverseList();
void insertNode(int, int);
void deleteNode(int);
void reverse();

struct Node {
	int data;
	struct Node* next;
}* head = NULL;


int main(int argc, char* argv[]){
	int option, no_of_nodes, position, data;
	
	while(1){
		printf("1. Create List\n");
		printf("2. Traverse List\n");
		printf("3. Insert Node\n");
		printf("4. Delete Node\n");
		printf("5. Reverse List\n");
		printf("10. Exit\n");
		printf("\nEnter choice: ");
		scanf("%d", &option);

		switch(option){
			case 1: 
				printf("\nEnter No. of Nodes to Create: ");
				scanf("%d", &no_of_nodes);
				createList(no_of_nodes);
				break;

			case 2:
				traverseList();
				break;
			case 3:
				printf("\nEnter position: "); scanf("%d", &position);
				printf("\nEnter data: "); scanf("%d", &data);
				printf("\n");
				insertNode(position, data);
				break;
			
			case 4:
				printf("\nEnter position: "); scanf("%d", &position);
				deleteNode(position);
				break;

			case 5:
				reverse();
				traverseList();
				break;
				
			case 10:
				exit(0);
			default:
				printf("\nWrong Option!\n");
		}
	}

	return 0;
}

void reverse(){
	struct Node* p = head;
	struct Node* q = head->next;
	struct Node* r = head->next;

	r = r->next;
	p->next = NULL;

	while(r != NULL){
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}

	head = q;
}

void deleteNode(int pos){
	struct Node* p = head;
	struct Node* q = p;
	int count = 1;

	if(head == NULL){
		printf("List is empty!\n");
	} else if (pos == 1){
		head = head->next;
		free(p);
		printf("Node deleted!\n");
		return;
	}

	while(q != NULL && count < pos){
		p = q;
		q = q->next;
		count++;
	}

	if(count == pos){
		p->next = q->next;
		q->next = NULL;
		free(q);

		printf("Node deleted!\n");
	} else {
		printf("Position doesn't exist!\n\n");
	}
}

void insertNode(int pos, int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;

	if(pos == 1){
		temp->next = head;
		head = temp;
	} else {
		int count = 1;
		struct Node* p = head;
		
		while(p->next != NULL & count < pos - 1){
			p = p->next;
			count++;
		}

		if(count == pos-1){
			temp->next = p->next;
			p->next = temp;
		} else {
			printf("\nPosition doesn't exist!\n\n");
		}
	}
}


void createList(int no_of_nodes){
	struct Node* temp, *p;
	int data, i;
	
	for(i=1; i<=no_of_nodes; i++){
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->next = NULL;

		printf("Enter data for Node %d:", i);
		scanf("%d", &temp->data);

		if(head == NULL){
			head = temp;
		} else {
			p = head;
			while(p->next != NULL) p = p->next;
			
			p->next = temp;
		}
	}
}

void traverseList(){
	struct Node* p = head;
	printf("\n");
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->next;
		if(p != NULL) printf("-> ");
	}

	printf("\n\n");
}
