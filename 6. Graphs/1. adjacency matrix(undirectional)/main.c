//graphs
//undirrectional adjacency matrix

#include "stdio.h"
#include "stdlib.h"

void graph(int matrix[20][20]){

    int n;
    printf("enter the number of edges: ");
    scanf("%d",&n);

	int i, vertex1, vertex2;
	for(i=0; i<n; i++){
		printf("enter the vertex1 : ");
		scanf("%d",&vertex1);
		printf("enter the vertex2 : ");
		scanf("%d",&vertex2);

		matrix[vertex1][vertex2] = 1;
		matrix[vertex2][vertex1] = 1;


	}
}

void display(int matrix[20][20], int v){

	int i, j;

	printf("  ");
	for(i=0; i<v; i++){
        printf("%d\t",i);
	}

    printf("\n");

    for(i=0; i<v; i++)
        printf("--------");

	printf("\n");


	for(i=0; i<v; i++){
	    printf("%d|",i);
		for(j=0; j<v; j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n\n");
	}
}

void main(){

	int v;
	printf("enter the number of vertex in the graph: ");
	scanf("%d",&v);


	int matrix[20][20];

	int i, j;
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			matrix[i][j] = 0;
		}
	}

	graph(matrix);

	printf("\n\n");

	display(matrix,v);
}
