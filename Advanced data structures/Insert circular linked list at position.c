#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *tail,*newnode,*temp;
    int choice=1,position,i=1,length=0;
    tail=0;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
            length++;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
            length++;
        }
        printf("Do you wanna continue (0,1): ");
        scanf("%d",&choice);
    }
    
    printf("Enter the position at which you wanna insert the element: ");
    scanf("%d",&position);
    if(position<0 && position>length){
        printf("Invalid Position");
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=tail->next;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    temp=tail->next;
    printf("The elements in the list are: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
}

