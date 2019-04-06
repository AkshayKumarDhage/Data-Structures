//deleting a node at nth position of a list

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head , int x){
	struct node *temp ;
	struct node *temp1 ;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(*head==NULL)
		*head = temp;
	else{
		temp1 = *head ;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next = temp;

	}

}

void print(struct node *head){
    struct node *temp = head;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
}

void delete(struct node **head, int p){
	struct node *temp = *head;
	if(p==0){
        *head = temp->next;
        free(temp);
        return;
	}
	int i;
	for(i=0;i<p-2;i++){
		temp=temp->next;
	}
	struct node *temp1;
	temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
}

void main(){

	struct node *head;
	head = NULL;

	int n,i,x,p;

	printf("enter the number of elements: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("enter the number: ");
		scanf("%d",&x);
		insert(&head,x);
		print(head);
		printf("\n\n");
	}

	printf("enter the position of number to be deleted: ");
	scanf("%d",&p);

	delete(&head,p);
	print(head);
}
