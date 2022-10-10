#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;  
};

void linkedlisttraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void searchElement(struct node*ptr){
    int n;
    int c=0;
    printf("Enter an element you want to search:\n");
    scanf("%d",&n);
    while (ptr->data!=n){
          ptr=ptr->next;
          c=c+1;  
        }
    if(ptr->data==n){
        printf("ELement found!\n");
        printf("At index: %d",c);
    }
    else{
    printf("Element not found!");
    }
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
    searchElement(head);

    return 0;
}