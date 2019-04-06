//heap

#include "stdio.h"
#include "stdlib.h"

int array[100];
int 	n = 10;

void insert(int num, int index){

	int parent;

	while(index > 0){
		parent = (index - 1)/2;
		if(num<=array[parent]){
			array[index] = num;
			return;
		}

		array[index] = array[parent];
		index = parent;
	}

	array[0] = num;

}

void display(){
	if(n==0){
		printf("heap is empty");
		return;
	}

    int i;
	for(i=0; i<n; i++){
		printf("%d ",array[i]);
	}
}

void delete(int num){

	int i;
	for(i=0; i<n; i++){
		if(num==array[i])
			break;
	}

	if(num!=array[i]){
		printf("number does not exist in the heap");
		return;
	}

	array[i] = array[n-1];
	n = n-1;
	//int parent = (i-1)/2;

	/*if(array[i] > array[parent]){
		insert(array[i],i);
		return;
	}*/

	int left = 2*i + 1;
	int right = 2*i + 2;

	while(right<n){

		if(array[i]>=array[left]  &&  array[i]>=array[right]){
			return;
		}

		if(array[right]>=array[left]){
			int temp;
			temp = array[i];
			array[i] = array[right];
			array[right] = temp;
			i = right;

		}
		else {
			int temp;
			temp = array[i];
			array[i] = array[left];
			array[left] = temp;
			i = left;
		}

		left = 2*i + 1;
		right = 2*i + 2;

	}

	if(left==n-1 && array[i]<array[left]){
		int temp;
		temp = array[i];
		array[i] = array[left];
		array[left] = temp;
	}

}

void main(){

	int i;
	int n = 10;

	for(i=0; i<n; i++){
		int num;
		printf("enter the number: ");
		scanf("%d",&num);
		insert(num,i);
	}

	printf("\n\n");

	display();

	printf("\n\n");

	int d;
	for(i=0; i<n; i++){
        printf("enter the number to delete: ");
        scanf("%d",&d);
        delete(d);
        display();
        printf("\n\n");
	}
}
