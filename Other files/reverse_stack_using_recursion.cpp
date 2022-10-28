//given a stack, reverse it using recursion!

#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>&s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
void insertatbottom(stack<int>&s,int t)
{
    if(s.empty()==1)
    {s.push(t); return;}

    int c=s.top();
    s.pop();
    insertatbottom(s,t);
    s.push(c);
}
void reverse(stack<int>&s)
{
   
   if(s.empty()==1) return;

    int t=s.top();
    s.pop();
    reverse(s);
    insertatbottom(s,t);
}
int main()
{
   stack<int> s;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       int data;
       cin>>data;
       s.push(data);
   }
    reverse(s);
    print(s);
    return 0;
}
