//binary tree
//implentation using arrays

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left ;
	struct node *right;
};

struct node *newNode (int a){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = a;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int a){
	if(root == NULL){
		root = newNode(a);
		return root;
	}
	else if( a<root->data ){
		root->left = insert(root->left,a);
	}
	else{
		root->right = insert(root->right,a);
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

void main(){
	struct node *root = NULL;

	int a[] = { 15 , 10 , 20 , 6 , 12 , 17 , 25 } ;


	int i;
	root = insert(root,a[0]);

	for(i=1; i<(sizeof(a)/sizeof(int)); i++)
		insert(root,a[i]);


	inorder(root);

}
