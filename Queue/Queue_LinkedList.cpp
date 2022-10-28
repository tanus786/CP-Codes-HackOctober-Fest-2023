#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void create(int item,struct Node *&temp)
{
    temp= ( struct Node*)malloc(sizeof(struct Node));
    temp->data=item;
    temp->next=NULL;
}

void enqueue()
{
    int item;
    cout << "Enter the element to insert in the queue" << endl;
    cin >> item;
    struct Node *newNode;
    create(item,newNode);
    struct Node *ptr;
    if(newNode==NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
       if(front==NULL)
       {
           front=newNode;
           rear=newNode;
       }
       else
       {
          rear->next=newNode;
          rear=newNode;  
       }
    }

}

void dequeue()
{
    struct Node *ptr;
    if(front==NULL)
    {
        cout << "UnderFlow" << endl;
        return ;
    }
    else
    {
        ptr=front;
        front=front->next;
        free (ptr);
    }
}

void display()
{
    struct Node *ptr;
    ptr=front;
    if(front==NULL)
    cout << "Queue is empty" << endl;
    else
    {
        while(ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
    }
}

int main()
{
    struct Node *t;
    int choice;
    do
    {
        cout << "\n1.Create the Queue" << endl;
        cout << "2.Insert Element in the queue \n3.Delete element in the queue \n4.Display the elements of the queue" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1 : {
                        int element;
                        cout << "Enter the element to create the queue" << endl;
                        cin >> element;
                        create(element,t);
                        front=t;
                        rear=t;
                     }
                     break;
            case 2 : enqueue();
                     break;
            case 3 : dequeue();
                     break;
            case 4 : display();
                     break;
            default : cout << "You have enetered wrong choice " << endl;
                      break;

        }
    } while (1);
    
    return 0;
}