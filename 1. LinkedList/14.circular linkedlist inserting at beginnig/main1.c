//circular linked list atbeg

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void atbeg(struct node **rear, int x){
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
	}
}

void display(struct node *rear){
	struct node *temp = rear->next;

	do{
		printf("%d ",temp->data);
		temp = temp->next;

	}while(rear->next != temp);
}

void main(){
	struct node *rear;
	rear = NULL;

	atbeg(&rear,3);
	atbeg(&rear,2);
	atbeg(&rear,1);

	display(rear);

}