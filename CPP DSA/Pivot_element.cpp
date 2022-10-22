//pivot element in c++

#include<iostream>
using namespace std;

void initarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        a[i]=0;
    }
}

void acceptarray(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
}

int pivotelement(int a[], int n)   //function has return type int so return the index of pivot element
{
    int s1 = 0;
    int s2 = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(i==0 || i==n-1) /* this condition added */
            continue;

        s1=0, s2=0; /* make s1 s2 zero inside for loop */

        for(int k = 0; k<i; k++) /* k<i not k<=i */
        {
            s1 += a[k];
        }
        for(int j = i+1; j<n; j++) /* j=i+1 not j=i+2 */
        {
            s2 +=a[j];
        }
        if(s1 == s2)
        {
            return i;               //returning the index of pivot element
        }

    }
    return -1;         //return -1 if pivot not found
}

int main(void)
{
    int a[100];
    int n =0;
    cout<<"enter the no of elements"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
    initarray(a,n);
    acceptarray(a,n);
    int x=pivotelement(a,n);         //call pivot element function and take the value returned

    if(x==-1)
        cout<<"no pivot";
    else
        cout<<"pivot element "<<a[x];


    return 0;
}