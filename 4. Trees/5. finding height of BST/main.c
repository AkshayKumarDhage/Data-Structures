//BST
//finding the height of tree

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define max(x,y) (x>y)?(x):(y)

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int n){
	if(root== NULL){
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

int height(struct node *root){
	if(root==NULL){
		return -1;
	}
	else{
        int lheight, rheight;
        lheight = height(root->left);
        rheight = height(root->right);
        int value = max(lheight, rheight);
        return (value + 1);
	}
}

void main(){
	struct node *root = NULL;

	root = insert(root,6);
	insert(root,2);
	insert(root,7);
	insert(root,1);
	insert(root,3);
	insert(root,5);
	insert(root,8);

	inorder(root);

	printf("\n\n");

	int max_depth = height(root);

	printf("%d is the height of the tree",max_depth);
}
