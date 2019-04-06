//ascending order

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};


void insert(struct node **head,int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;

	if(*head==NULL || (*head)->data > x){
		temp->next = *head;
		*head = temp;
	}
	else{
		struct node *temp1 = *head;
		while(temp1!=NULL){
			if(temp1->data <= x && (temp1->next==NULL || temp1->next->data > x)){
				temp->next = temp1->next;
				temp1->next = temp;
				return;
			}
			temp1=temp1->next;  
		}
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

	insert(&head,2);
	insert(&head,5);
	insert(&head,1);
	insert(&head,3);
	insert(&head,4);

	display(head);
}