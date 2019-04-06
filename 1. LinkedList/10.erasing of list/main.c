//erasing of list

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head, int x){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

struct node* erase(struct node *head){
	struct node *temp;

	while(head!=NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}

int count(struct node *head){
    int c=0;
    while(head!=NULL){
        head = head->next;
        c++;
    }
    return c;
}

void main(){
	struct node *head;
	head = NULL;

	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	printf("number of elements in the list: %d ",count(head));
	printf("\n\n");

	head = erase(head);

	printf("number of elements in the list: %d ",count(head));
}
