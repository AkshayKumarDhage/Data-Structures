//stacks application
//reversing of string

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct node{
	char data;
	struct node *next;
};

void push(struct node **top, char s){

	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = s;
	if(*top == NULL){
		*top = temp;
		temp->next = NULL;
	}
	else{
		temp->next = *top;
		*top = temp;
	}
}

char pop(struct node **top){
	struct node *temp = *top;
	*top = temp->next;
	return temp->data;
	free(temp);
}

void main(){
	struct node *top;
	top = NULL;

	char str[20];
	printf("enter the string: ");
	scanf("%s",str);
	printf("\n");
	printf("entered string is: %s\n\n",str);

	int i;
	char chr;
	char str1[20];
	for(i=0;i<strlen(str); i++)
		push(&top,str[i]);

	for( i=0; i<strlen(str); i++){
        chr = pop(&top);
		str1[i] = chr;
	}

	for(i=0; i<strlen(str); i++){
		str[i] = str1[i];
	}


	printf("reversed string is: %s\n",str);


}
