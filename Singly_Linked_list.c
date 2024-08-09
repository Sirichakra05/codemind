//Implementation Of a Singly Linked List
#include<stdio.h>
#include<stdlib.h>

//Self Referential Structure
typedef struct node{
	int data;
	struct node *next;  //pointer to node
}Node;

//alias name
//typedef struct node Node;

//Taking head as a global variable
Node *head = NULL;
void insert_at_head(int val) {
	// Creating a newNode
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = NULL;
	if (head == NULL) {  // if there are no nodes already 
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	
}
void insert_at_tail(int val) {
	// Creating a newNode
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = NULL;
	//Stop at the last node
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node *temp = head;
	
	   while (temp->next != NULL) {
		   temp = temp->next;
	    }
       temp->next = newNode;  // Connecting last and newNodes
   	
}
void delete_at_head() {
	if(head == NULL) {
		printf("Linked List is empty.Deletion is not possible\n");
	}
	else {
		Node *temp = head;  // To be deleted node
		head = head->next;
		free(temp);   // Deallocate the memory for node1
	}
}
void delete_at_tail() {
	if (head == NULL) {      //  Empty Linked List
		printf("Linked List is empty.Deletion is not possible\n");
		return;
	}
	else if (head->next == NULL) {  // Linked List with single node
		Node *delNode = head;
		head = NULL;
		free(delNode);
		return;
	}
	else{
	
	 // Reach last but one node
	Node *temp = head ;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	Node *delNode = temp->next;
	temp->next = NULL;
	free(delNode);
	
    }
	
}
void display(){
	if(head == NULL) {
		printf("No Nodes to display\n");
	}
	else {
		Node *temp = head ;
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
int main() {
	int ch;
	//Infinite Loop
	while (1) {
		printf("Enter\n1. Insert at head\n2. Insert at tail\n3. Display\n4. Delete at head\n5. Delete at tail\n^. Any other to exit\n");
		scanf("%d", &ch);
		if (ch == 1) {
			//Implement insert at head
			int val;
			printf("Enter a value for the node to be inserted : ");
			scanf("%d", &val);
			insert_at_head(val); //Function call
		}
		else if (ch == 2) {
			//Implement insert at tail
			int val;
			printf("Enter a value for the node to be inserted : ");
			scanf("%d", &val);
			insert_at_tail(val);
		}
		else if (ch == 3) {
			//Implement display
			display();
		}
		else if (ch == 4) {
			//Implement delete at head
			delete_at_head();
			
		}
		else if (ch == 5) {
			//Implement delete at tail
			delete_at_tail();
		}
		else {
			printf("Thank you for the testing.ADIEU!!\n");
			break;
		}
		
		
	}
	
}
