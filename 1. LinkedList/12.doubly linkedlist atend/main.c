//doubly linkedlist atend

#include "stdio.h"
#include "stdlib.h"

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void atend(struct node **head, int x){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = x;
	if(*head==NULL){
		*head = temp;
		temp->prev = NULL;
		temp->next = NULL;
    }
	else{
		struct node *temp1 = *head;
		while(temp1->next!=NULL){
			temp1 = temp1->next;
		}
		temp->prev = temp1;
		temp1->next = temp;
		temp->next = NULL;
	}
}

void display(struct node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}

void main(){
	struct node *head;
	head = NULL;

	atend(&head,1);
	atend(&head,2);
	atend(&head,3);
	atend(&head,4);

	display(head);
}
