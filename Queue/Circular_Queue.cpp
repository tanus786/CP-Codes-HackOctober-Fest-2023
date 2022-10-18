#include<stdio.h>
#include<stdlib.h>
#define size 8
int array[size],front = -1 ,rear = -1;

int isFull()
{
    if((front == rear+1) || (front == 0 && rear == size-1))
    return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1)
    return 1;
    return 0;
}

void Enqueue()
{
    if(isFull())
    {
        printf("\nQueue is Full\n");
        return ;
    }
    else
    {
    int item;
    printf("Enter the item to insert\n");
    scanf("%d",&item);
    if(front == -1)  
    front = 0;
    rear = (rear+1)%size;
    array[rear] = item;
    printf("\nElement inserted is : %d",item);
    }

}

void dequeue()
{
    int item;
    if(isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    else
    {
        item = array[front];
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front +1) % size;
        }
        printf("\n Deleted element is : %d",item);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    for(int i=front;i<=rear;i=(i+1)%size)
    {
        printf("%d ",array[i]);
    }
    
    printf("\n");
}

int main()
{

    
     int choice;
     do
     {
         printf("\n1.To insert Element \n2.To delete element \n3.To display element \n Enter your choice\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1 : Enqueue();
                      break;
             case 2 : dequeue();
                      break;
             case 3 : display();
                      break;
            default : printf("You have entered worng choice\n");
                      break;
         }
     } while (1);
     
    return 0;
}