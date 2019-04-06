//linkedlist
//circular linkedlist

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head, int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;

	if(*head == NULL){
		temp->next = temp;
		*head = temp;
	}
	else{
		struct node *temp1 = *head;
		while(temp1->next!=*head){
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = *head;
	}
}

void display(struct node *head){
	struct node *temp = head;
	do{
        printf("%d ",temp->data);
        temp = temp->next;
	}while(temp!=head);
}

void main(){
	struct node *head = NULL;

	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);

	display(head);
}
