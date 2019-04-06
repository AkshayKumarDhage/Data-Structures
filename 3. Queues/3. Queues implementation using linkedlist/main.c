//Queues
//Queues implementation using linkedlist

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void enqueue(struct node **front, struct node **rear, int value){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = value;
	temp->next = NULL;

    printf("%d is enqueued\n",temp->data);

    if(*front==NULL){
		*front = temp ;
		*rear = temp;
		return;
	}

	(*rear)->next = temp;       //important
	*rear = temp;

}

void dequeue(struct node **front, struct node **rear){
	struct node *temp = *front;
	if(*front == NULL){
		printf("Queue is empty\n");
		return;
	}
	int value;
	value = temp->data;
	if(*front == *rear){
		*front = NULL;
		*rear = NULL;
	}
	else{
		(*front) = (*front)->next;
	}
	printf("%d is dequeued\n",value);
	free(temp);
}

void main(){
	struct node *front;
	struct node *rear;
	front = NULL;
	rear = NULL;

	enqueue(&front, &rear, 1);
	enqueue(&front, &rear, 2);
	enqueue(&front, &rear, 3);
	enqueue(&front, &rear, 4);

	printf("\n\n");

	dequeue(&front, &rear);
	dequeue(&front, &rear);
	dequeue(&front, &rear);
	dequeue(&front, &rear);
	dequeue(&front, &rear);
}
