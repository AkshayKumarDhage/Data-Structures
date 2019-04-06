//circular list inserting at nth position

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void atn(struct node **rear, int x, int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	if(*rear==NULL){
        temp->next = temp;
        *rear = temp;
	}

    if(n==1){
		temp->next = (*rear)->next;
		(*rear)->next = temp;
	}
	else{
        int i;
		struct node *temp1 = (*rear)->next;
		for(i=0; i<n-2; i++){
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}

void display(struct node *rear){
	struct node *temp = (rear)->next;
	do{
		printf("%d ",temp->data);
		temp = temp->next;

	}while(temp != rear->next );
}

void main(){
	struct node *rear;
	rear = NULL;

	atn(&rear,3,2);
	atn(&rear,1,1);
	atn(&rear,2,2);

	display(rear);
}
