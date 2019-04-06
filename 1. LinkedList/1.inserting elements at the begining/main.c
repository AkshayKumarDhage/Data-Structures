/*DataStructures in C*/
//LinkedList - adding elements at the beginning of list



#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node* next;
};


void insert(struct node **head,int x){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = *head;
	*head = temp;
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

	int n,i,x;
	printf("enter the number of elements in list: ");
	scanf("%d",&n);
	printf("\n");

	for(i=0;i<n;i++){
		printf("enter the number: ");
		scanf("%d",&x);
		printf("List is: ");
		insert(&head,x);
		print(head);
		printf("\n\n");
	}

}

