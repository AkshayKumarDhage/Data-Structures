//BST
//finding minimum and maximum in a binary search tree

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int n){
	struct node *temp = (struct node*)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int n){
	if(root==NULL){
		root = newNode(n);
		return root;
	}
	else if(n<=root->data){
		root->left = insert(root->left, n);
	}
	else{
		root->right = insert(root->right, n);
	}
	return root;
}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void min(struct node *root){
	while(root->left!=NULL){
		root = root->left;
	}
	printf("%d is the minimum\n",root->data);
}

void max(struct node *root){
	while(root->right!=NULL){
		root = root->right;
	}
	printf("%d is the maximum\n",root->data);
}

void main(){
	struct node *root = NULL;

	root = insert(root,5);
	insert(root,2);
	insert(root,6);
	insert(root,1);
	insert(root,3);
	insert(root,4);
	insert(root,7);

	inorder(root);

	printf("\n\n");

	min(root);

	printf("\n\n");

	max(root);

}