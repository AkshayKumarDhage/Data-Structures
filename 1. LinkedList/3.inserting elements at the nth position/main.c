//linkedlist - adding elements at the nth position of the list

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node* next;
};


void insert(struct node **head,int x,int n){
	struct node* temp;
	struct node* temp1;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(n==1){
		temp->next = *head;
		*head = temp;
		return;
	}
	else{
		temp1 = *head;
		int i;
		for(i=0;i<n-2;i++){
			temp1=temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
    }

}

void print(struct node *head){
	while(head!=NULL){
		printf("%d",head->data);
		head=head->next;
	}
}

void main(){
    struct node *head;
    head = NULL;

	insert(&head,2,1);
	insert(&head,3,2);
	insert(&head,5,3);
	insert(&head,4,1);
	print(head);

}
