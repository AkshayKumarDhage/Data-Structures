//evaluating prefix

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct node{
	int data;
	struct node *next;

};

void evaluate(char exp[]){
	struct node *top;
	top = NULL;

	int i;
	int length = strlen(exp);

	for(i=length-1; i>=0; i--){
		if(isdigit(exp[i]))
			push(&top,(exp[i]-'0'));

		if( (exp[i]=='+') || (exp[i]=='-') || (exp[i]=='*') || (exp[i]=='/') || (exp[i]=='^') ){
			int op1 = pop(&top);
			int op2 = pop(&top);

			int result;

			if( (exp[i]=='+') )
				result = op1 + op2;
			if( (exp[i]=='-') )
				result = op1 - op2;
			if( (exp[i]=='*') )
				result = op1 * op2;
			if( (exp[i]=='/') )
				result = op1/op2;
			if( (exp[i]=='^') )
				result = pow(op1,op2);

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
	printf("enter the valid prefix expression: ");
	scanf("%s",exp);

	evaluate(exp);

}
