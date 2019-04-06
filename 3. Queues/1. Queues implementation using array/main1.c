//Queues
//Queues using arrays

#include "stdio.h"
#include "stdlib.h"

#define max 20

void enqueue(int *a, int *front, int *rear, int data){
	if(*rear == max-1){
		printf("Queue is full\n");
		return;
	}

	if(*front==-1){
		(*front)=0;		                                                 //(*front)++
		(*rear)=0;
		a[*rear]=data;
		printf("%d enqueued\n",a[*rear]);
	}
	else{
		(*rear)++;
		a[*rear] = data;
		printf("%d enqueued\n",a[*rear]);
	}

}

void dequeue(int *a, int *front, int *rear){
	if(*front==-1){
		printf("Queue is empty\n");
		return;
	}

	int data;
	data = a[*front];
    printf("%d dequeued\n",data);

	if(*front == *rear){
		*front = -1;
		*rear = -1;
	}
	else
		(*front)++;



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
	dequeue(a, &front, &rear);
	dequeue(a, &front, &rear);
	dequeue(a, &front, &rear);
	dequeue(a, &front, &rear);
}
