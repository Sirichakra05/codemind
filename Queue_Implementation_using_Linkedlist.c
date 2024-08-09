//Queue Implementation using linkedlist
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
int size;
typedef struct Node Node;
Node* head = NULL;
Node* tail = NULL;
void enqueue(int val) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = val;
	newnode->next = NULL;
	newnode->prev = NULL; 
	if(head == NULL && tail == NULL) {
		head = newnode;
		tail = newnode;
	} else {
		newnode->next=head;
		newnode->prev=tail;
		head=newnode;
	}
}
void dequeue() {
	if(head==NULL&&tail==NULL){
		printf("No Queue");
	}else if(head==tail){
	Node*tobeDeleted =head;
		head==NULL;
		tail==NULL;
	}else{
		Node*tobeDeleted=head;
		head=head->next;
		head->prev=NULL;
		free(tobeDeleted);
	}
}	
void display(){
	if(head==NULL&&tail==NULL){
		printf("No Queue to display\n");
	}else{
		Node*temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}
int main(){
	printf("Enter the size of the queue: ");
	scanf("%d",&size);
	int ch;
	while(1){
		printf("Enter\n1. Enqueue\n2. Dequeue\n3. Display\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch==1){
			int val;
			printf("Enter the value to be enqueued: ");
			scanf("%d",&val);
			enqueue(val);
		}
		else if(ch==2){
			dequeue();
		}
		else if(ch==3){
			display();
		}
		else{
			break;
		}
	}
}
