/*
topic : Reversing nodes in linked list in c language
author : Sonali Rao

*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
} * head;
void createNode(int n)
{
    struct Node *newNode, *temp;
    int i, data;
    head = (struct Node *)malloc(sizeof(struct Node));
   if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;
        for (i = 2; i<=n; ++i)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == NULL)
            {
                printf("No data is allocated");
            }
            else
            {
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;
                temp = temp->next;
            }
        }
}}
void display()
{
    struct  Node *temp;
    if (head == 0)
    {
        printf("List is Empty");
    }
    else
    {
        temp = head;
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void Reverse(){
   struct  Node *cur=head;
   struct Node * prev =NULL;
   struct Node * next=NULL;
    while(cur!=NULL){
        next = cur ->next;
        cur -> next = prev;
        prev = cur ;
        cur = next;

    }
    head = prev ;

}
int main (){
    int n;
    printf("Enter no of nodes to be created :");
    scanf("%d",&n);
    
    createNode(n);
    
    display();
    printf("\n");
    printf("Reversed linked list is:");
    Reverse();
    display();
}