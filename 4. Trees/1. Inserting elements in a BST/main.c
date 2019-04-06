//Trees
//Binary Search Trees

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left;
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
		return newNode(n);
	}
	else if( n<=root->data ){
		root->left = insert(root->left,n);
	}
	else{
		root->right = insert(root->right,n);
	}
	return root;
}


void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void main(){
	struct node *root = NULL;

    printf("\n\n");
	root = insert(root,15);
	insert(root,10);
	insert(root,20);
	insert(root,6);
	insert(root,12);
	insert(root,17);
	insert(root,25);

    printf("\n\n");
	inorder(root);
}
