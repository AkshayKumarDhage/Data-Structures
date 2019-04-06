//sorting of linkedlist

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};


void insert(struct node **head, int x){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(*head==NULL)
		*head = temp;
	else{
		struct node *temp1 = *head;
	    while(temp1->next!=NULL){
	    	temp1 = temp1->next;
	    }
	    temp1->next = temp;
	}

}


void bubsort(struct node **head){
	struct node *temp1, *temp2, *temp;
	temp2 = NULL;
	int swapped;

	if(temp1==NULL)
		return;

	do{
		swapped = 0;
		temp1 = *head;
		while(temp1->next!=NULL){
			if(temp1->data > temp1->next->data){
				temp = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = temp;
				swapped = 1;
			}
			temp1= temp1->next;
		}
		temp2 = temp1;

	}while(swapped);

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


	insert(&head,5);
	insert(&head,4);
	insert(&head,9);
	insert(&head,2);
	insert(&head,1);

	display(head);
	printf("\n\n");

	bubsort(&head);
	display(head);

}
