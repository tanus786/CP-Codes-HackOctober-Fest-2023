
#include <iostream>
using namespace std;
   #define N 5
   int quene[N];
   int front=-1;
   int rear =-1;
   void enquene()
   {  int x;
   cout<<"enter the value to enter"<<endl;
   cin>>x;  
       if(rear==N-1)
   {
       cout<<"Overflow"<<endl;
   }
   else if(front==-1&& rear==-1)
   { front=rear=0;
   quene[rear]=x;
   }
   else{
       rear++;
       quene[rear]=x;
   }
   }

   void dequene()
   { 
       if(front==-1 && rear==-1)
       {
           cout<<"Underflow"<<endl;
       }
       else if(front==rear)
       {
           front=rear=-1;
       }
       else{
           cout<<"Dequened element is"<<quene[front];
           front++;
       }
 }
 void display()
 {
     if(front==-1&& rear==-1)
     {
        cout<<"list is empty"<<endl;
     }
     else{
          for(i=front;i<rear+1;i++)
          {
              cout<<quene[i]<<endl;
          }
     }
 }
 void peek()
 {
     if(front==-1&& rear==-1)
     {
         cout<<"quene is empty"<<endl;
     }
     else{
         cout<<quene[front]<<endl;
     }
 }
 int main()
{
    int ch;
    do
    { cout<<"enter choice 1:enquene 2:dequene 3:display 4:peek"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: enquene();
               break;
        case 2: dequene();
                break;
        case 3: display();
                break;
        case 4: peek();
                break;
        default: cout<<"Invalid choice"<<endl;
    }
    } while (ch!=0);


}


