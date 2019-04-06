//merging of list

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head,int x){
	struct node *temp,*temp1;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;

	if(*head==NULL || (*head)->data > x){
		temp->next = *head;
		*head = temp;
	}
	else{
		temp1 = *head;
		while(temp1!=NULL){
			if(temp1->data < x && (temp1->next==NULL || temp1->next->data > x)){
				temp->next = temp1->next;
				temp1->next = temp;
				return;
			}
			temp1 = temp1->next;

		}
	}

}

void display(struct node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head =  head->next;
	}
}

void merge(struct node *head1, struct node *head2, struct node **head3){
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	if(head1 && head2){
		if(head1->data <= head2->data){
			*head3 = head1;
			head1 = (*head3)->next;
		}
		else{
			*head3 = head2;
			head2 = (*head3)->next;
		}

	}
	struct node *newhead = *head3;
	while(head1 && head2){
		if(head1->data <= head2->data){
			newhead->next = head1;
			newhead = head1;
			head1 = newhead->next;
		}
		else{
			newhead->next = head2;
			newhead = head2;
			head2 = newhead->next;
		}
	}

	if(head1==NULL)
		newhead->next = head2;
	if(head2==NULL)
		newhead->next = head1;

}

void main(){
	struct node *head1,*head2,*head3;
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;

	insert(&head1,1);
	insert(&head1,2);
	insert(&head1,3);
	insert(&head1,4);
	insert(&head1,5);

	printf("first list: ");
	display(head1);
	printf("\n\n");

	insert(&head2,6);
	insert(&head2,7);
	insert(&head2,8);
	insert(&head2,9);
	insert(&head2,10);

	printf("second list: ");
	display(head2);
	printf("\n\n");


	merge(head1,head2,&head3);

	printf("Merged list: ");
	display(head3);
}
