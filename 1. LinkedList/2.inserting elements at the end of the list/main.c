//linkedlist - adding elements at the end of the list

#include "stdio.h"
#include "stdlib.h"

struct node{
     int data;
     struct node *link;
};

void insert(struct node **head,int x){
        struct node *temp;
        struct node *temp1;

        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        temp->link = NULL;
        if(*head==NULL)
            *head = temp;
        else{
            temp1 = *head;
            while(temp1->link!=NULL){
                temp1=temp1->link;
            }
            temp1->link = temp;
        }

}

void print(struct node *head){
        while(head!=NULL){
            printf("%d",head->data);
            head=head->link;
        }
}

void main(){
        struct node *head;
        head = NULL;

        int n,i,x;

        printf("enter the number of elements: ");
        scanf("%d",&n);

        for(i=0;i<n;i++){
            printf("enter the number: ");
            scanf("%d",&x);

            printf("list is: ");
            insert(&head,x);
            print(head);
            printf("\n\n");
        }
}
