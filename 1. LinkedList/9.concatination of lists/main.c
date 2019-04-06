//concatination of two lists

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head, int x){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = x;
	temp->next = NULL;

	if(*head==NULL)
		*head = temp;
	else{
		struct node *temp1 = *head;
		while(temp1->next!=0){
			temp1=temp1->next;
		}
		temp1->next = temp;
	}

}

void display(struct node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}

void concat(struct node **head1, struct node **head2){
	if(*head1==NULL)
		*head1 = *head2;
	else{
		if(*head2!=NULL){
			struct node *temp = *head1;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = *head2;
		}
	}
}

void main(){
	struct node *head1, *head2;
	head1 = NULL;
	head2 = NULL;

	insert(&head1,1);
	insert(&head1,2);
	insert(&head1,3);
	insert(&head1,4);
	insert(&head1,5);

	printf("1st list: ");
	display(head1);
	printf("\n\n");


	insert(&head2,6);
	insert(&head2,7);
	insert(&head2,8);
	insert(&head2,9);
	insert(&head2,10);

	printf("2nd list: ");
	display(head2);
	printf("\n\n");

	printf("concat list is: ");
	concat(&head1,&head2);
	display(head1);


}
