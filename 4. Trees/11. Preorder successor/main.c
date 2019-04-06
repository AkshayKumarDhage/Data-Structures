//bst
//inorder predecessor

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct node *newNode(int n){
	struct node *temp = (struct node*)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

struct node *insert(struct node *root, int n){
	if(root==NULL)
		return newNode(n);

	if(n<root->data){
		root->left = insert(root->left,n);
		root->left->parent = root;

	}
	else if(n>root->data){
		root->right = insert(root->right,n);
		root->right->parent = root;
	}
	else
		return root;

	return root;
}

int max(struct node *root){
	struct node *temp = root;

	while(temp->right!=NULL){
		temp = temp->right;
	}

	return temp;
}

struct node *inorderpredecessor(struct node *root, struct node *p){
	if(p->left!=NULL){
		return max(p->left);
	}

	struct node *par = p->parent;
	while(p!=NULL && p == par->left){
		p = par;
		par = par->parent;
	}
	return par;
}

void main(){
	struct node *root = NULL;

	root = insert(root,20);
	root = insert(root,8);
	root = insert(root,22);
	root = insert(root,4);
	root = insert(root,12);
	root = insert(root,10);
	root = insert(root,14);

	struct node *temp;
	temp =  root->left->right->right;

	struct node *predecessor;
	predecessor = inorderpredecessor(root,temp);

	if(predecessor!=NULL)
		printf("inorderpredecessor of %d is %d",temp->data,predecessor->data);
	else
		printf("inorderpredecessor does'nt exist");
}
