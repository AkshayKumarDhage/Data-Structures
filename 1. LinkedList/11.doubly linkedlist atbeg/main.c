//doubly linked list

#include "stdio.h"
#include "stdlib.h"

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void atbeg(struct node **head, int x){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node ));
	temp->prev = NULL;
	temp->data = x;
	temp->next = *head;
	*head = temp;
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

	atbeg(&head,1);
	atbeg(&head,2);
	atbeg(&head,3);
	atbeg(&head,4);

	display(head);

}