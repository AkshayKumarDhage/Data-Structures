//circular Queues
//implementation using circular array

#include "stdio.h"
#include "stdlib.h"

#define max 5

void enqueue(int *a, int *front, int *rear, int data){
	if( ((*front == 0) && (*rear == max-1)) || ((*rear )+ 1 == *front ) ){
		printf("Queue is full\n");
		return;
	}

	(*rear) = ((*rear)+1)% max;
	a[*rear] = data;
	printf("%d is enqueued\n",a[*rear]);

	if(*front==-1)
        (*front) = ((*front)+1)% max;
}

void dequeue(int *a, int *front, int *rear){
	if(*front == -1){
		printf("Queue is empty\n");
		return;
	}

	int data;
	data = a[*front];
	printf("%d is dequeued\n",data);

	if(*front == *rear){
		(*front) = -1;
		(*rear) = -1;
	}
	else{
		(*front) = ((*front)+1)% max;
	}

}

void main(){
	int a[max];
	int front, rear;
	front = -1;
	rear = -1;

	enqueue(a, &front, &rear, 1);
	enqueue(a, &front, &rear, 2);
	enqueue(a, &front, &rear, 3);
	enqueue(a, &front, &rear, 4);
	enqueue(a, &front, &rear, 5);

	printf("\n\n");

	dequeue(a, &front, &rear);
	dequeue(a, &front, &rear);


	enqueue(a, &front, &rear, 6);
	enqueue(a, &front, &rear, 7);
	enqueue(a, &front, &rear, 8);
	enqueue(a, &front, &rear, 9);
}
