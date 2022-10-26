#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int top;
    int maxSize;
    int* array;
    Stack(int max)
    {
        top=-1;
        maxSize=max;
        array=new int[max];
    }
    int isFull()
    {
        if(top==maxSize-1)
        cout<<"Will not be able to push maxSize reached"<<endl;
        return top==maxSize-1;
    }

    int isEmpty()
    {
        if(top==-1)
        cout<<"Will not be able to pop minSize reached"<<endl;
        return top==-1;
    }
    void push(int item)
    {
        if(isFull()) return;
        array[++top]=item;
        cout<<"We have pushed "<<item<<" to stack"<<endl;
    }
    int pop()
    {
        if(isEmpty()) return INT_MIN;
        return array[top--];
    }
    int peek()
    {
        if(isEmpty()) return INT_MIN;
        return array[top];
    }
};

int main()
{
    Stack stack(10);
    stack.push(5);
    stack.push(10);
    stack.push(15);
    int flag=1;
    while(flag)
    {
        if(!stack.isEmpty())
            cout<<"We have popped "<< stack.pop()<<" from stack"<<endl;
        else
            cout<<"Can't Pop stack must be empty\n";
            
           flag=0;
    }

}
