#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;           
    struct node *next;  
}*head;


void createList(int n);

void insertAtBeginning(int data);

void insertAtEnd(int data);

void insertAtPos(int data, int position);

void traverseList();


int main()
{
    int n, data ,position;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nFinal data in the linked list \n");
    traverseList();

    
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertAtBeginning(data);

    printf("\nFinal data in the linked list \n");
    traverseList();
    
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertAtEnd(data);

    printf("\nFinal data in the linked list \n");
    traverseList();

    
    printf("\nEnter the position where you want to insert new node: " );
    scanf("%d", &position);
    printf("\nEnter data you want to insert at position %d of the list: ", position);
    scanf("%d", &data);
    insertAtPos(data, position);

    printf("\nFinal data in the linked list \n");
    traverseList();;
    return 0;
}


void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->next = NULL; 

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode;
                
                temp = temp->next; 
            }
        }

        printf("Singly linked list created successfully\n");
    }
}



void insertAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 

        head = newNode;         

        printf("Data inserted successfully\n");
    }
}

void insertAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL; 

        temp = head;

        
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; 

        printf("Data inserted successfully\n");
    }
}

void insertAtPos(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL;

        temp = head;

       
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            
            newNode->next = temp->next; 

            temp->next = newNode;

            printf("Data inserted successfully\n");
        }
        else
        {
            printf("Unable to insert data at the given position\n");
        }
    }
}

void traverseList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d\n", temp->data); 
            temp = temp->next;                
        }
    }
}
