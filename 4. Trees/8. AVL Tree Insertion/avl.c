//avl

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

struct node *newNode(int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

int max(int x, int y){
    return (x>y)?x:y ;
}

int height(struct node *root){
	if(root==NULL)
		return 0;
	return root->height;
}

int getbalance(struct node *root){
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}

struct node *rightRotate(struct node *root){
	struct node *x = root->left;
	struct node *temp = x->right;

	x->right = root;
	root->left = temp;

	root->height = max(height(root->left),height(root->right))+1;
	x->height = max(height(x->left),height(x->right )) +1 ;

	return x;
}

struct node *leftRotate(struct node *root){
	struct node *x = root->right ;
	struct node *temp  = x->left;

	x->left = root;
	root->right = temp;

	root->height = max(height(root->left),height(root->right)) +1;
	x->height = max(height(x->left),height(x->right)) +1;

	return x;
}

struct node *insert(struct node *root, int n){
	if(root==NULL)
		return newNode(n);

	if(n<root->data)
		root->left = insert(root->left,n);
	else if(n>root->data)
		root->right = insert(root->right,n);
	else
		return root;

	root->height = 1 + max( height(root->left),height(root->right) );

	int balance = getbalance(root);

	//LL
	if(balance>1 && n<root->left->data)
		return rightRotate(root);

	//RR
	if(balance<-1 && n>root->right->data)
		return leftRotate(root);

	//LR
	if(balance>1 && n>root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//RL
	if(balance<-1 && n<root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preorder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void main(){
	struct node *root = NULL;

	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);
	root = insert(root,40);
	root = insert(root,50);
	root = insert(root,25);

	preorder(root);
}
