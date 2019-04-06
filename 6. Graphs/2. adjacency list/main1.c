//graphs
//adjacency list

#include "stdio.h"
#include "stdlib.h"

int n = 4;

struct node{
	int data;
	struct node *next;
};

struct list{
	struct node *head;
};

struct list *adjlist[4];

void addnode(int s, int d){

	struct node *src;
	if(adjlist[s]->head==NULL){
		src = (struct node *)malloc(sizeof(struct node ));
		src->data = s;
		src->next = NULL;
		adjlist[s]->head = src;

	}

	struct node *dest = (struct node *)malloc(sizeof(struct node ));
	dest->data = d;
	dest->next = NULL;

	struct node *temp = adjlist[s]->head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = dest;


}

void printlist(){

	int i;
	for(i=0; i<n; i++){

		struct node *temp = adjlist[i]->head;

		printf("%d\t",i);

		while(temp){
			printf("%d\t",temp->data);
			temp = temp->next;
		}

		printf("\n");
	}

}

void main(){


	int i;
	for(i=0; i<n; i++){
		adjlist[i] = (struct list *)malloc(sizeof(struct list ));
		adjlist[i]->head = NULL;
	}

	addnode(0,1);
	addnode(0,3);
	addnode(1,2);

	printlist();


}
