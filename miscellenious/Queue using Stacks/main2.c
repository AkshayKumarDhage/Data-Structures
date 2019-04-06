//implementing queue using stacks

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void push(struct node **top, int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;

	if(*top == NULL){
		temp->next = NULL;
		*top = temp;
	}
	else{
		temp->next = *top;
		*top = temp;
	}
}

void dequeue(struct node **top){
	struct node *temp = *top;
	if(*top == NULL){
		printf("queue is empty\n");
		return;
	}

	if((*top)->next == NULL){
        printf("%d is dequeued\n",temp->data);
        *top = NULL;
        free(temp);
        return;
	}

	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	struct node *temp1 = temp->next;
	printf("%d is dequeued\n",temp1->data);
	temp->next = NULL;
	free(temp1);

}

void main(){
	struct node *top = NULL;

	push(&top,1);
	push(&top,2);
	push(&top,3);
	push(&top,4);
	push(&top,5);

	dequeue(&top);
	dequeue(&top);
	dequeue(&top);
	dequeue(&top);
	dequeue(&top);
	dequeue(&top);

}
