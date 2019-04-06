//check for balance of paranthesis

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct node{
	char data;
	struct node *next;
};


void check(char exp[]){
	struct node *top;
	top = NULL;

	int length = strlen(exp);

	int i;
	for(i=0; i<length; i++){

		if( (exp[i]=='(') || (exp[i]=='{') || (exp[i]=='[') )
			push(&top,exp[i]);

		if( (exp[i]==')') || (exp[i]=='}') || (exp[i]==']') ){

			if(top == NULL ){
				printf("unbalanced expression \n");
				printf("\n");
				exit(0);
			}

			char character = pop(&top);

			if( (character=='(' ) && (exp[i]==')') )
				continue;
			else if( (character=='{') && (exp[i]=='}') )
				continue;
			else if( (character=='[') && (exp[i]==']') )
				continue;
			else{
				printf("unbalanced expression ");
				printf("\n");
				exit(0);
			}


		}

	}
	if( top == NULL ){
		printf("balanced expression ");
		printf("\n");
		exit(0);
	}
	else{
		printf("unbalanced expression ");
		printf("\n");
		exit(0);
	}

}


void push(struct node **top, char exp){
	struct node *temp = (struct node*)malloc(sizeof(struct node ));
	temp->data = exp;
	temp->next = *top;
	*top = temp;

}


int pop(struct node **top){
	struct node *temp = *top;
	char character;
	character = temp->data;
	*top = temp->next;
	free(temp);
	return character;

}


/*void match(char character1, char character2){
	if( (character1=='(' ) && (character2==')') )
		return 1;
	else if( (character1=='{') && (character2=='}') )
		return 1;
	else if( (character1=='[') && (character2==']') )
		return 1;
	else
		return 0;

}*/


void main(){
	char exp[20];
	printf("enter the expression: ");
	scanf("%s",exp);

	printf("\n");

	check(exp);

}
