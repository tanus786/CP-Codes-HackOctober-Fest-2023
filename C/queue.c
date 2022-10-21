#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 3

void insert();
void dilet();
void display();

char value[MAX];
int front=-1;
int rear=-1;

int main()
{
    system("CLS");
    int ch;
    printf("\t\t\t\t     QUEUE OPERATIONS       \n");
    printf("\t\t\t\t----------------------------\n");
    printf("\t\t\t\t|      1. INSERT           |\n");
    printf("\t\t\t\t|      2. DELETE           |\n");
    printf("\t\t\t\t|      3. DISPLAY          |\n");
    printf("\t\t\t\t|      4. EXIT             |\n");
    printf("\t\t\t\t----------------------------\n");
    printf("\n\t\t\t\tEnter choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        insert();
        break;
    case 2:
        dilet();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\n\t\t\t\tWrong choice..\n\n\t\t\t\tTry again.");
        getch();
        main();
    }
}
void insert()
{
    char item;
    if(rear==MAX-1)
    {
        printf("\n\t\t\t\tQueue Overflow");
        getch();
        main();
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("\n\t\t\t\tEnter Value : ");
        scanf(" %c", &item);
        rear++;
        value[rear]=item;
    }
    main();
}
void dilet()
{
    if(front==-1||front>rear)
    {
        printf("\n\t\t\t\tQueue Underflow.");
    }
    else
    {
        printf("\n\t\t\t\tDeleted item is : %c\n", value[front]);
        front++;
        printf("\n\t\t\t\tAfter Deleted item is : \n");
        for(int i=front; i<=rear; i++)
        {
            printf("\t\t\t\t                       |%c|\n", value[i]);
        }
    }
    getch();
    main();
}
void display()
{
    if(front==-1||front>rear)
    {
        printf("\n\t\t\t\tQueue is Empty.");
    }
    else
    {
        printf("\n\t\t\t\tItems in the Queue : \n");
        for(int i=front; i<=rear; i++)
        {
            printf("\t\t\t\t                    |%c|\n", value[i]);
        }
    }
    getch();
    main();
}
