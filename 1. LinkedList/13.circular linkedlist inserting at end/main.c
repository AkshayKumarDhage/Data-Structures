//circular linkedlist
//inserting at the end

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insertatend(struct node **rear, int x){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;

	if(*rear==NULL){
		temp->next = temp;
		*rear = temp;
	}
	else{
		temp->next = (*rear)->next;
		(*rear)->next = temp;
		*rear = temp;
	}
}

void display(struct node *rear){
	struct node *temp = rear->next;

	do{
        printf("%d ",temp->data);
        temp = temp->next;

	}while(temp != rear->next);
}

void main(){
	struct node *rear;
	rear = NULL;

	insertatend(&rear,1);
	insertatend(&rear,2);
	insertatend(&rear,3);
	insertatend(&rear,4);

	display(rear);

}
