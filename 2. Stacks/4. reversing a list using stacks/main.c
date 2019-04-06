//reversing a list using stacks

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void atbeg(struct node **head, int x){
	struct node *temp = (struct node*)malloc(sizeof(struct node ));
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

void display(struct node *head){
	struct node *temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}


void reverse(struct node **head, struct node **top){
	struct node *temp = *head;
	
	while(temp!=NULL){
		
		struct node *temp1 = (struct node *)malloc(sizeof(struct node ));
		temp1->data = temp;
		temp1->next = *top;
		*top = temp1;
		temp = temp->next;

	}

	while(*top!=NULL){

		struct node *temp2 = *top;
		*top = temp2->next ;
		struct node *temp3 = temp2->data;
		printf("%d ",temp3->data);
		free(temp3);
		free(temp2);
	}
}

void main(){
	struct node *head, *top;
	head = NULL;
	top = NULL;

	atbeg(&head,1);
	atbeg(&head,2);
	atbeg(&head,3);
	atbeg(&head,4);
	atbeg(&head,5);


	printf("The list is: ");
	display(head);
	printf("\n\n");

	printf("The reversed list is: ");
	reverse(&head,&top);

}
