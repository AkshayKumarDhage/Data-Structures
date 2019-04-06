//stacks using linkedlist

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void push(struct node **top, int x){
	
	struct node *temp ;
	temp = (struct node *)malloc(sizeof(struct node ));
	if(temp == NULL){
		printf("stack is full\n");
		return;
	}


	temp->data = x;
	temp->next = *top;
	*top = temp;
}

void pop(struct node **top){
	if(*top == NULL){
		printf("stack is empty");
		return;
	}

	struct node *temp = *top;
	*top = temp->next;
	printf("%d is popped\n\n",temp->data);
	free(temp);
}

void main(){
	struct node *top;
	top = NULL;

	push(&top,1);
	push(&top,2);
	push(&top,3);
	push(&top,4);
	push(&top,5);

	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);

}
