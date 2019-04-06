//bst
//search

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left , *right;
};

struct node *new(int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int n){
	if(root==NULL){
		root = new(n);
		return root;
	}
	else if(n<=root->data){
		root->left = insert(root->left, n);
	}
	else if(n>root->data){
		root->right = insert(root->right, n);
	}
	return root;
}

void inorder(struct node *root){
	struct node *temp = root;
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}

void search(struct node *root, int s){
    if(root==NULL){
         printf("not found");
         exit(0);
    }
    if(root->data == s){
        printf("found");
        exit(0);
    }
    else if(s<root->data){
        search(root->left,s);
    }
    else if(s>root->data){
        search(root->right,s);
    }

}

void main(){
	struct node *root = NULL;

	root = insert(root,5);
	insert(root,2);
	insert(root,7);
	insert(root,1);
	insert(root,3);
	insert(root,6);
	insert(root,8);

	inorder(root);

	printf("enter the number: ");
	int n;
	scanf("%d",&n);

	search(root,n);

}
