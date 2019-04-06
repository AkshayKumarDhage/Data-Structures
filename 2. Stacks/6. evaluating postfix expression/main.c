//evaluating postfix done;

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct node{
	int data;
	struct node *next;
};

void evaluate(char exp[]){
	struct node *top;
	top = NULL;

	int length = strlen(exp);
	int i;

	for(i=0; i<length; i++){
		if(isdigit(exp[i]))
			push(&top, (exp[i]-'0'));
		if( (exp[i]=='+') || (exp[i]=='-') || (exp[i]=='*') || (exp[i]=='/') || (exp[i]=='^') ){

			int op1 = pop(&top);
			int op2 = pop(&top);

			int result;

			if(exp[i]=='+')
				result = op1 + op2;
			if(exp[i]=='-')
				result = op1 - op2;
			if(exp[i]=='*')
				result = op1 * op2;
			if(exp[i]=='/')
				result = op1 / op2;
			if(exp[i]=='^')
				result = op1 ^ op2;

			push(&top,result);

		}
	}

	int ans;
	ans = pop(&top);
	printf("result is %d",ans);

}

void push(struct node **top, int exp){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = exp;
	temp->next = *top;
	*top = temp;
}

int pop(struct node **top){
	struct node *temp = *top;
	int operand;
	operand = temp->data;
	*top = temp->next;
	free(temp);
	return operand;
}

void main(){
	char exp[20];
	printf("enter a valid postfix expression: ");
	scanf("%s",exp);

	evaluate(exp);
}