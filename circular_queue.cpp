#include <iostream>
using namespace std;
int cqueue[5],front=-1,rear=-1,n=5;

void enqueue(){
    if((rear+1)%n==front)
        cout<<"Cqueue overflow"<<endl;
    else{
        if (front==-1)
            front=0;
        int val;
        rear=(rear+1)%n;
        cout<<"Enter a value : ";
        cin>>val;
        cqueue[rear]=val;
    }
}

void dequeue(){
    if(front==-1 && rear==-1)
        cout<<"Cqueue underflow"<<endl;
    else if (front==rear)
    {
        cout<<"Deleted element : "<<cqueue[front]<<endl;
        front=-1;
        rear=-1;
    }
    
    else{
        cout<<"Deleted element : "<<cqueue[front]<<endl;
        front=(front+1)%n;
    }
}

void display(){
    if(front==-1 && rear==-1)
        cout<<"Cqueue underflow"<<endl;
    else{
        int i=front;
        cout<<"Element ";
        while(i!=rear){
            cout<<cqueue[i]<<" ";
            i=(i+1)%n;
        }
        cout<<cqueue[i]<<endl;
    }
}

int main()
{
    cout<<"1. Enqueue\n2.Dequeue\n3. Traverse\n-- Other key to exit --\n";
    while (true)
    {   
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }
    return 0;
}