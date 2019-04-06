//avl deletion

#include "stdio.h"
#include "stdlib.h"

struct node {
	int data;
	struct node *left;
	struct node *right;
	int height;
};

struct  node *newNode(int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node ));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

int max(int x, int y){
	return (x>y)?x:y;
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

	root->height = 1 + max( height(root->left),height(root->right) );
	x->height = 1 + max( height(x->left),height(x->right) );


	return x;
}

struct node *leftRotate(struct node *root){
	struct node *x = root->right;
	struct node *temp = x->left;

	x->left = root;
	root->right = temp;

	root->height = 1 + max( height(root->left),height(root->right) );
	x->height = 1 + max( height(x->left),height(x->right) );


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

struct node *min(struct node *root){
	struct node *temp = root;

	while(temp->left!=NULL)
		temp = temp->left;

	return temp;
}

struct node *delete(struct node *root, int n){
	if(root==NULL)
		return ;

	if(n<root->data)
		root->left = delete(root->left,n);
	else if(n>root->data)
		root->right = delete(root->right,n);
	else{

		if(root->left==NULL && root->right==NULL ){
			free(root);
			root = NULL;
		}

		else if(root->left==NULL){
			struct node *temp = root;
			root = temp->right;
			free(temp);
		}
		else if(root->right==NULL){
			struct node *temp = root;
			root = temp->left;
			free(temp);
		}

		else{
			struct node *temp = min(root->right);
			root->data = temp->data;
			root->right = delete(root->right,temp->data);
		}

	}

	if(root==NULL)
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
	struct node *temp = root;

	if(temp!=NULL){
		printf("%d ",temp->data);
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

	printf("\n\n");

	delete(root,10);

	preorder(root);
}
