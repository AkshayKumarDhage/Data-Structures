//stack using array

#include "stdio.h"
#include "stdlib.h"

#define size 100

struct stack{
	int a[size];
	int top;
};

void init(struct stack *s){
	s->top = -1;
}

void push(struct stack *s, int x){
	if(s->top == size-1){
		printf("stack is full");
		return;
	}

	s->top++;
	s->a[s->top] = x;
}

int pop(struct stack *s){
	if(s->top == -1){
		printf("stack is empty");
		return NULL;
	}

	int data;
	data = s->a[s->top];
	s->top--;
	return data;
}

void main(){
	struct stack s;

	init(&s);

	push(&s,1);
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);

    int i;
	i = pop(&s);
	if(i!=NULL)
		printf("%d is popped out from stack\n\n",i);


	i = pop(&s);
	if(i!=NULL)
		printf("%d is popped out from stack\n\n",i);


	i = pop(&s);
	if(i!=NULL)
		printf("%d is popped out from stack\n\n",i);


	i = pop(&s);
	if(i!=NULL)
		printf("%d is popped out from stack\n\n",i);



	i = pop(&s);
	if(i!=NULL)
		printf("%d is popped out from stack\n\n",i);



	i = pop(&s);
	if(i!=NULL)
		printf("%d is popped out from stack");

}
