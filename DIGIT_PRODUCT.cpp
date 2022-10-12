#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    int k=n,prod=1;
    while(k>0)
    {
        prod=prod*(k%10);
        k=k/10;
    }
    cout<<"Product of digits of given number is : "<<prod<<endl;
}