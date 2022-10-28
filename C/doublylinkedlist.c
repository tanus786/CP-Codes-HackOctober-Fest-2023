#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
    int info;
    struct Node *next, *prev;
};

struct Node *head =NULL;

//CREATING THE NODE

struct Node * CreateNode()
{
    struct Node *NewNode;
    int Value;
    printf("\n Enter the value to be inserted : ");
    scanf("%d",&Value);
    NewNode=(struct Node *)malloc(sizeof(struct Node));
    NewNode->info=Value;
    NewNode->next=NULL;
    NewNode->prev=NULL;
    return(NewNode); 
}

//CREATING THE DOUBLY LINED LIST 

struct Node * CreateDLL(struct Node * head)
{
    struct Node *ptr,*qtr;
    int ch=0;
    printf(" \n Lets Create the Doubly Linked List!! \n");
    do
    {
        ptr=CreateNode();
        if(head==NULL)
        {
            head=ptr;
        }
        else
        {
            qtr=head;
            while(qtr->next!=NULL)
            {
                qtr=qtr->next;
            }
            qtr->next=ptr;
            ptr->prev=qtr;
        }
        printf("\n Do you want do add more values(0/1)? ");
        scanf("%d",&ch);
    }while(ch!=0); 
    return(head);
}

//Displaying the Doubly Linked List

struct Node *DisplayDLL(struct Node * head )
{
    struct Node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("\n LIST IS EMPTY!! ");
    } 
    else
    {
        printf("\n The created Doubly Linked List is: \n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }
    }
    return(head);
}

//INSERTING IN BEGINNING

struct Node *InsertAtBeg(struct Node *head )
{
    struct Node * NewNode;
    NewNode=CreateNode();
    head->prev=NewNode;
    NewNode->next=head;
    head=NewNode;
    printf("\n NewNode Inserted!");
    return(NewNode);
}

//INSERING IN THE BETWEEN

struct Node *InsertInBetween(struct Node * head)
{
    struct Node *newnode,*ptr;
    int pos,count=1;
    ptr=head;
    newnode=CreateNode();
    printf("\n Enter the position to insert the element :  ");
    scanf("%d",&pos);
    while(count<pos-1)
    {
        ptr=ptr->next;
        count++;
    }
    newnode->next=ptr->next;
    newnode->prev=ptr;
    ptr->next->prev=newnode;
    ptr->next=newnode;
    printf("\n Node Inserted");
    return(head);    
}

//INSERTING AT THE END

struct Node *InsertAtEnd(struct Node * head)
{
    struct Node * ptr,*qtr;
    qtr=head;
    ptr=CreateNode();
    while(qtr->next!=NULL)
    {
        qtr=qtr->next;
    }
    qtr->next=ptr;
    ptr->prev=qtr;
    printf("\n NewNode Inserted!");
    return(head);
}

//UPDATING THE DOUBLY LINKED LIST

struct Node *UpdateDLL(struct Node * head)
{
    struct Node *ptr ;
    int old,new;
    ptr=head;
    printf("\n Enter the old value: ");
    scanf("%d",&old);
    printf("\n Enter the new value : ");
    scanf("%d",&new);
    while(ptr!=NULL)
    {
        if(ptr->info==old)
        {
            ptr->info=new;
        }
        ptr=ptr->next;
    }
    printf("\n VALUE UPDATED!");
    return(head);
}

//DELETING AT BEGINNING

struct Node *DeleteAtBeg(struct Node * head)
{
    struct Node * ptr;
    ptr=head;
    head=ptr->next;
    head->prev=NULL;
    printf(" \n Node Deleted! ");
    return(head);
}

// //DELETING IN BETWEEN
  
struct Node * DeleteInBetween(struct Node *head)
{
    struct Node *ptr,*qtr;
    ptr = head;
    int count=1,pos;
    printf("\n Enter the position to delete : ");
    scanf("%d",&pos);
    while(count<pos-1)
    {
        ptr = ptr->next;
        count++;
    }
    ptr->next = ptr->next->next;
    ptr->next->next->prev = ptr;
    printf("\n Node Deleted!");
    return(head);
}

//DELETING AT END

struct Node *DeleteAtEnd(struct Node * head)
{
    struct Node *ptr;
    ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
    printf("\n Node Delete! ");
    return(head);

}

int main()
{
  
    int ch1;
    do{
        printf("\n\n\n\t DOUBLY LINKED LIST \n ");
        printf("\n 1. CREATE LIST ");
        printf("\n 2. DISPLAY LIST  ");
        printf("\n 3. INSERT AT BEGIN ");
        printf("\n 4. INSERT IN BETWEEN ");
        printf("\n 5. INSERT AT END ");
        printf("\n 6. UPDATEDLL ");
        printf("\n 7. DELETE AT BEGINNING ");
        printf("\n 8. DELETE IN BETWEEN ");
        printf("\n 9. DELETE AT END ");
        printf("\n 0. EXIT ");
        printf("\n\n ENTER YOUR CHOICE: ");
        scanf("%d",&ch1);

        switch(ch1)
        {
            case 1:
                head=CreateDLL(head);
                break;
    
            case 2:
                head= DisplayDLL(head);
                break;

            case 3:
                head=InsertAtBeg(head);
                break;

            case 4:
                head=InsertInBetween(head);
                break;
            
            case 5:
                head=InsertAtEnd(head);
                break;

            case 6:
                head=UpdateDLL(head);
                break;

            case 7:
                head= DeleteAtBeg(head);
                break;
            
            case 8:
                head = DeleteInBetween(head);
                break;

            case 9:
                head =DeleteAtEnd(head);
                break;

            case 0:
                printf("\n\t THANK-YOU \n ");
                exit(0);  
        }
    }while(1);
}
