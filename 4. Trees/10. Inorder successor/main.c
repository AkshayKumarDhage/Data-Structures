//bst
//inorder successor

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

	if(n<=root->data){
		struct node *temp;
		temp = insert(root->left,n);
		root->left = temp;
		temp->parent = root;
	}
	else if(n>root->data){
		struct node *temp;
		temp = insert(root->right,n);
		root->right = temp;
		temp->parent = root;
	}

	return root;
}

struct node *inordersuccessor(struct node *root, struct node *s){
	if(s->right!=NULL){
		return min(s->right);
	}

	struct node *p = s->parent;
	while(p!=NULL && s == p->right){
		s = p;
		p = p->parent;
	}

	return p;
}

int min(struct node *root){
	struct node *temp = root;

	while(temp->left!=NULL){
		temp = temp->left;
	}

	return temp;
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
	temp = root->left->right->right;

    struct node *succ;
	succ = inordersuccessor(root,temp);

	if(succ!=NULL)
		printf("inorder successor of %d is %d",temp->data,succ->data);
	else
		printf("inorder successor doen't exit");


}
