//Binary search tree
//searching element in a Binary tree

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left ;
	struct node *right;
};

struct node *newNode(int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int n){
	if(root == NULL){
		root = newNode(n);
		return root;
	}
	if( n<=root->data ){
		root->left = insert(root->left, n);
	}
	else{
		root->right = insert(root->right, n);
	}
	return root;
}

void search(struct node *root, int s){
	while(root!=NULL){
		if(root->data == s){
			printf("FOUND");
			exit(0);
		}
		else if( s<root->data ){
			root = root->left;
		}
		else if( s>root->data ){
			root = root->right;
		}
	}
	printf("NOT FOUND");

}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void main(){
	struct node *root = NULL;

	root = insert(root,6);
	insert(root,2);
	insert(root,8);
	insert(root,1);
	insert(root,3);
	insert(root,4);
	insert(root,9);

	inorder(root);

	printf("\n\n");

	int s;
	printf("enter the number to be searched: ");
	scanf("%d",&s);

	search(root,s);
}
