//implementation of stacks from queue

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void enqueue(struct node **front, struct node **rear, int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->next = NULL;

	if(*front==NULL){
		(*front)=temp;
		(*rear)=temp;
		return;
	}

	(*rear)->next = temp;
	*rear = temp;

}

void pop(struct node **front, struct node **rear){
	if(*front==NULL){
		printf("stack is empty\n");
		return;
	}
	
	if(*front == *rear){
		printf("%d is popped\n",(*rear)->data);
		*front = NULL;
		*rear = NULL;
		return;
	}
	
	struct node *temp = *front;
	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	
	struct node *temp1 = temp->next;
	printf("%d is popped\n",temp1->data);
	temp->next = NULL;
	(*rear) = temp;
	free(temp1);

}

void main(){
	struct node *front, *rear;
	front = NULL;
	rear = NULL;

	enqueue(&front, &rear, 1);
	enqueue(&front, &rear, 2);
	enqueue(&front, &rear, 3);
	enqueue(&front, &rear, 4);

	pop(&front, &rear);
	pop(&front, &rear);
	pop(&front, &rear);
	pop(&front, &rear);
	pop(&front, &rear);
}