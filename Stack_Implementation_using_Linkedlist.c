// Stack implementation using a Linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node Node;
Node* head = NULL;
int size;
int top = -1;
void PUSH(int val){
	if (top == size-1) {
		printf("stack is full\n");
		return;
	}
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->next = NULL;
	if(head == NULL) {
		head = newnode;
	} else {
		newnode->next = head;
		head = newnode;
	}
	top++;
}
void POP() {
	if(head == NULL) {
		printf("Stack is Empty\n");
		return;
	}
	Node* to_be_delete = head;
	printf("%d is popped out of the stack: \n",head->data);
	head = head->next;
	free(to_be_delete);
	top--;
}
void Display() {
	if(head == NULL) {
		printf("Stack is Empty\n");
		return;
	} 
	Node *temp = head;
	while (temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	printf("Enter size of the stack: \n");
	scanf("%d",&size);
	int ch;
	while (1) {
		printf("Enter\n1.PUSH\n2.POP\n3.Display\nAny other\n");
		scanf("%d",&ch);
		if (ch == 1) {
			int val;
			printf("Enter a value to Push: \n");
			scanf("%d",&val);
			PUSH(val);
		} else if (ch == 2) {
			POP();
		} else if (ch == 3) {
			Display();
		} else {
			break;
		}
	}
}
