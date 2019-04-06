//bst
//deleting a node in bst

#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left, *right;
};

struct node *newNode(int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
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

struct node *min(struct node *root){
	struct node *temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

struct node *delete(struct node *root, int n){
	if(root==NULL)
		return NULL;
	else if(n<root->data){
		root->left = delete(root->left,n);
	}
	else if(n>root->data){
		root->right = delete(root->right,n);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			free(root);
			root = NULL;
		}
		else if(root->left == NULL){
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL){
			struct node *temp = root;
			root = root->left;
			free(temp);
		}
		else{
			struct node *temp = min(root->right);
			root->data = temp->data;
			root->right = delete(root->right,temp->data);
		}

	}
    return root;
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

	printf("enter the number to delete: ");
	int n;
	scanf("%d",&n);

	delete(root,n);

	printf("\n\n");

	inorder(root);
}
