#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;  
    struct node * prev;  
};

void linkedlisttraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

node*linkedlistreverse(struct node*ptr){
    struct node *prev=NULL;
    struct node *next=NULL;
    while(ptr!=NULL){
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    return prev;
}

int main(){
    struct node*head;
    struct node*first;
    struct node*second;
    
    head=(struct node*)malloc(sizeof(struct node*));
    first=(struct node*)malloc(sizeof(struct node*));
    second=(struct node*)malloc(sizeof(struct node*));

    head->data=8;
    head->next=first;

    first->data=9;
    first->next=second;

    second->data=10;
    second->next=NULL;

    linkedlisttraversal(head);
    printf("\nAfter reversing:\n");
    head=linkedlistreverse(head);
    linkedlisttraversal(head);

    return 0;
}