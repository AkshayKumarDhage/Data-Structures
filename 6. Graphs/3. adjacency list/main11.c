//graphs
//adjacency list

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};


struct list{
	struct node *head;
};

void addnode(struct list *adjlist[]){

	int i;
	
	int e;
	printf("enter the number of edges: ");
	scanf("%d",&e);

	for(i=0; i<e; i++){

		int s, d;
		printf("enter the source and destination of edge: ");
		scanf("%d\t%d",&s,&d);
		printf("\n");

		if(adjlist[s]->head == NULL){
			struct node *src = (struct node *)malloc(sizeof(struct node ));
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

}

void display(struct list *adjlist[], int v){

	int i;
	for(i=0; i<v; i++){

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

	int v;
	printf("enter the number of vertices: ");
	scanf("%d",&v);

	struct list *adjlist[v];

	int i;
	for(i=0; i<v; i++){
		adjlist[i] = (struct list *)malloc(sizeof(struct list ));
		adjlist[i]->head = NULL; 
	}

	addnode(adjlist);

	display(adjlist,v);
}