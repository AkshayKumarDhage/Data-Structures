//heap

#include "stdio.h"
#include "stdlib.h"

int a[100];
int n=5;

void insert(int num, int index){

	int parent;

	while(index>0){

		parent = (index-1)/2;
		if(num>=a[parent]){
			a[index] = num;
			return;
		}

		a[index] = a[parent];
		index = parent;
	}

	a[0] = num;

}

void delete(int num){

    int i;
	for(i=0; i<n; i++){
		if(num == a[i])
            break;
	}

	if(num!=a[i]){
		printf("number does not exist");
		return;
	}


	a[i] = a[n-1];
	n = n-1;

	int left = 2*i + 1;
	int right = 2*i + 2;


	while(right<n){

		if(a[i]<=a[left] && a[i]<=a[right])
			return;

		if(a[left]<a[right]){
			int temp;
			temp = a[i];
			a[i] = a[left];
			a[left] = temp;
			i = left;
		}
		else{
			int temp;
			temp = a[i];
			a[i] = a[right];
			a[right] = temp;
			i = right;
		}

		left = 2*i + 1;
		right = 2*i + 2;

	}

	if(left==n-1 && a[left]<a[i]){
		int temp;
		temp = a[i];
		a[i] = a[left];
		a[left] = temp;
	}


}

void display(){

	if(n==0){
		printf("heap is empty");
	}

	int i;
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
}


void main(){
	int i;
	int n = 5;

	for(i=0; i<n; i++){

		int num;
		printf("enter the number: ");
		scanf("%d",&num);
		insert(num,i);
	}

	display();

	printf("\n\n");


	for(i=0; i<n; i++){
		int d;
		printf("enter the number to delete: ");
		scanf("%d",&d);
		delete(d);
		printf("\n\n");
		display();
		printf("\n\n");
	}

}
