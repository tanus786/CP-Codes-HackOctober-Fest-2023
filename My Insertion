#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertionAtBeginning();  
void insertionAtLast();  
void insertionAtSpecified();  
void deletionAtBeginning();  
void deletionAtLast();  
void deletionAtSpecified();  
void show();  
void search();  
void main()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose any option from the below list.\n");  
        printf("\n................................................\n");  
        printf("\n1.Insert at Beginning\n2.Insert at Last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice:\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertionAtBeginning();  
            break;  
            case 2:  
            insertionAtLast();  
            break;  
            case 3:  
            insertionAtSpecified();  
            break;  
            case 4:  
            deletionAtBeginning();  
            break;  
            case 5:  
            deletionAtLast();  
            break;  
            case 6:  
            deletionAtSpecified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            show();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter a valid choice.\n");  
        }  
    }  
}  
void insertionAtBeginning()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter the element to insert:\n");  
    scanf("%d",&item);  
 
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted successfully!!\n");  
}  
 
}  
void insertionAtLast()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter the element to insert:\n");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
 
       }  
     printf("\nNode inserted successfully!!\n");  
    }  
void insertionAtSpecified()  
{  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("\nEnter the location:\n");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\nLess than %d elements", loc);  
               return;  
           }  
       }  
       printf("\nEnter the element to insert:\n");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("\nNode inserted successfully!!\n");  
   }  
}  
void deletionAtBeginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nNode deleted successfully!!\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nNode deleted successfully!!\n");  
    }  
 
}  
void deletionAtLast()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nNode deleted successfully!!\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nNode deleted successfully!!\n");  
    }  
}  
void deletionAtSpecified()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\nEnter the element after which the node is to be deleted:\n");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nNode deleted successfully!!\n");  
    }     
}  
void show()  
{  
    struct node *ptr;  
    printf("\nList:\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List!!\n");  
    }  
    else  
    {   
        printf("\nEnter element to search:\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nElement found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nElement not found.\n");  
        }  
    }     
 
}
