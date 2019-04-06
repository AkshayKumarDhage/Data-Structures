//heaps

#include "stdio.h"
#include "stdlib.h"

int a[100];

void insert(int num, int index){

	int parent;

	while(index > 0){
		parent = (index - 1)/2;

		if(num<=a[parent]){
			a[index] = num;
			return;
		}

		a[index] = a[parent];
		index = parent;
	}

	a[0] = num;
}

void display(int a[], int n){
	if(n==0){
		printf("heap is empty");
		return;
	}

    int i;
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
}

void main(){
	int i;
	int n = 7;

	for(i=0; i<n; i++){
		int num;
		printf("enter the number: ");
		scanf("%d",&num);
		insert(num,i);
	}

	display(a,n);


}
