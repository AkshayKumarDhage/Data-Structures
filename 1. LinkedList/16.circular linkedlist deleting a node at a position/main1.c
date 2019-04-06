//circular list deleting node at given position

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void atbeg(struct node **rear, int x){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	if(*rear==NULL){
		temp->next = temp;
		*rear = temp;
	}
	else{
		temp->next = (*rear)->next;
		(*rear)->next = temp;
	}
}

void delete(struct node **rear, int p){
	struct node *temp = (*rear)->next;

	if(p==1){
		(*rear)->next = temp->next;
		free(temp);
		return;
	}

	else{
		struct node *temp2 = *rear;
		int i;
		for( i=0; i<p-2; i++){
			temp = temp->next;
		}

		struct node *temp1 = temp->next;

		if(temp1->next == (temp2)->next){
			temp->next = (temp2)->next;
			free(temp2);
			*rear = temp;
			return;
		}

		temp->next = temp1->next;
		free(temp1);

	}
}

void display(struct node *rear){
	struct node *temp = rear->next;

	do{
		printf("%d ",temp->data);
		temp = temp->next;

	}while(temp!=rear->next);
}

void main(){
	struct node *rear;
	rear = NULL;

	atbeg(&rear,4);
	atbeg(&rear,3);
	atbeg(&rear,3);
	atbeg(&rear,2);
	atbeg(&rear,1);

	printf("list is: ");
	display(rear);
	printf("\n\n");

	int p;
	printf("enter the position: ");
	scanf("%d",&p);

	delete(&rear,p);

	display(rear);

}
