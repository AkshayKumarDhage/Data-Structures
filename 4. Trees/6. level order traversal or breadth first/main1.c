//bst
//level order bst

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left , *right;
};

struct qnode{
	int data;
	struct qnode *next;
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
	else if( n<=root->data ){
		root->left = insert(root->left, n);
	}
	else{
		root->right = insert(root->right, n);
	}
	return root;
}

void level(struct node **root){
	if(root == NULL)
		return;

	struct node *temp = *root;

	while(temp!=NULL){
		printf("%d ",temp->data);

		if(temp->left!=NULL)
			enqueue(temp->left);
		if(temp->right!=NULL)
			enqueue(temp->right);

		temp = dequeue();
	}

}

struct qnode *front = NULL;
struct qnode *rear = NULL;

void enqueue(struct node *new){
	struct qnode *temp = (struct qnode *)malloc(sizeof(struct qnode ));
	temp->data = new;
	temp->next = NULL;

	if(front == NULL){
		front = rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
}

int dequeue(){
	if(front == NULL)
		return;

	struct qnode *temp = front;

    int data = temp->data;

	if(front == rear){
		front = rear = NULL;
	}
	else
		front = front->next;

	free(temp);

	return data;
}

void main(){
	struct node *root = NULL;

	root = insert(root,1);
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,6);
	insert(root,7);

	level(&root);
}
