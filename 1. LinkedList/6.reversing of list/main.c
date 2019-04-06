//reversing a list

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head,int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node ));

	temp->data = x;
	temp->next = *head;
	*head = temp;
}

void reverse(struct node **head){
	struct node *temp1, *temp2, *temp3;
    temp1 = *head;
	temp2 = NULL;
	temp3 = NULL;

	while(temp1!=NULL){
		temp3 = temp1->next;
		temp1->next = temp2;
		temp2 = temp1;
		temp1 = temp3;
	}
	*head = temp2;
}

void display(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

void main(){
	struct node *head;
	head = NULL;

	insert(&head,5);
	insert(&head,4);
	insert(&head,3);
	insert(&head,2);
	insert(&head,1);

	display(head);
	printf("\n\n");

	reverse(&head);
	display(head);

}
