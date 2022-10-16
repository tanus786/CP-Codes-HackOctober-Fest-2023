
#include <iostream>
using namespace std;
#define N 5
int stack [N];
int top=-1;
void push()
{   int x;
    cout<<"enter data"<<endl;
    cin>>x;
    if(top==N-1)
{
    cout<<"overflow"<<endl;
}
    else{
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        cout<<"underflow"<<endl;
    }
    else{
        item=stack[top];
        top--;
        cout<<"Popped item"<<item<<endl;
}

}
void peek()
{
    if(top==-1)
    {
        cout<<"stack empty"<<endl;
    }
    else{
        cout<<"topmost element"<<stack[top]<<endl;
    }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        cout<<stack[i]<<endl;
    }
}
int main()
{
    int ch;
    do
    { cout<<"enter choice 1:push 2:pop 3:peek 4:display"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: push();
               break;
        case 2: pop();
                break;
        case 3: peek();
                break;
        case 4: display();
                break;
        default: cout<<"Invalid choice"<<endl;
    }
    } while (ch!=0);
      
    }



