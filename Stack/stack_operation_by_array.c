#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#define size  5
int stack[size] ;
int top = -1;

void push(int val)
{
    if(top == size-1)
    {
        printf("\n Overflow ");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop()
{
    int val;
    if(top == -1 )
    {
        printf("\n underflow ");
    }
    else
    {
        val = stack[top];
        top--;
        return(val);
    }
}

int peek()
{
    return(stack[top]);
}

void traverse()
{
    for(int i = top;i>=0;i--)
    {
        printf("\n %d",stack[i]);
    }
}


int main()
{
    int ch= 0;
    int val;
    do
    {
        printf("\n 1. Push ");
        printf("\n 2. Pop ");
        printf("\n 3. Peek ");
        printf("\n 4. show  ");
        printf("\n 5. Exit ");
        printf("\n Enter Choice :  ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\n Enter value :");
            scanf("%d",&val);
            push(val);
            break;

            case 2:
            val = pop();
            printf("\n popped element %d ",val);
            break;

            case 3:
            val = peek();
            printf("\n Value at the top : %d ",val);
            break;

            case 4:
            traverse();
            break;

            case 5:
            exit(0);
            
        }
    } while (ch!=0);
    
}
