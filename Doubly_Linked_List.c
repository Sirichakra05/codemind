//Doubly linked list implementation
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*prev;
	struct node*next;
};
typedef struct node Node;
Node*head=NULL;
Node*tail=NULL;
void insert_at_head(int val){
	//creating the node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->prev=NULL;
	newNode->next=NULL;
	newNode->data=val;
	if(head==NULL&&tail==NULL){
		head=newNode;
		tail=newNode;
	}else{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
}
void insert_at_tail(int val){
	//creating the node
	Node *newNode= (Node *)malloc(sizeof(Node));
	newNode->prev=NULL;
	newNode->next=NULL;
	newNode->data=val;
	if(head==NULL&&tail==NULL){
		head=newNode;
		tail=newNode;
	}else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
}
void delete_at_head(){
	if(head==NULL&&tail==NULL){
		printf("no linked list");
	}else if(head==tail){//list contains only one node
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
void delete_at_tail(){
	if(head==NULL&&tail==NULL){
		printf("no linked list");
	}else if(head==tail){//list conatins only one node
		Node*tobeDeleted=tail;
		head=NULL;
		tail==NULL;
	}else{
		Node*tobeDeleted=tail;
		tail->next=NULL;
		tail->prev=NULL;
		free(tobeDeleted);
		
	}
}
void display_from_left(){
	if(head==NULL&&tail==NULL){
		printf("No nodes to display\n");
	}else{
		Node*temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}
void display_from_right(){
	if(head==NULL&&tail==NULL){
		printf("No nodes to display\n");
	} else{
		Node *temp=tail;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->prev;
		} 
	}
	printf("\n");
}
int main()
{
	int ch;
	//infinite loop
	while(1){
			printf("Enter\n1. Insert at head\n2. Insert at tail\n3. Delete at head\n4. Delete at tail\n5. Display forward\n6. Display backward\n Anyother to exist\n");
		scanf("%d",&ch);
		if(ch==1){
			//implement insert at head
			int val;
			printf("Enter A value for the node to be inserted: ");
			scanf("%d",&val);
			insert_at_head(val);
		}else if(ch==2){
			int val;
			printf("Enter a value for the node to be inserted: ");
			scanf("%d ",&val);
			insert_at_tail(val);
		}else if(ch==3){
			delete_at_head();
		}else if(ch==4){
			delete_at_tail();
		}else if(ch==5){
			display_from_left();
		}else if(ch==6){
			display_from_right();
		}else{
			printf("Thank you\n");
			break;
		}			
	}
}
