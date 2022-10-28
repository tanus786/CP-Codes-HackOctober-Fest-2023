#include<iostream>
using namespace std;
void countingsort(int arr[], int r, int a)
{
    int count[r]={0};
    for(int i=0;i<a;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<r;i++)
    {
        count[i]+=count[i-1];
    }
    int oparr[a];
    for(int i=0;i<a;i++)
    {
        oparr[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<a;i++)
    {
        arr[i]=oparr[i];
    }
}
int main()
{
    int a, r;
    cout<<"Enter number of elements\n";
    cin>>a;
    cout<<"Enter the higher limit of range\n";
    cin>>r;
    system("cls");
    int inparr[a];
    cout<<"Enter the elements\n";
    for(int i=0;i<a;i++)
    {
        while(1)
        {
            cout<<"Enter an element between 0 and "<<r<<endl;
            cin>>inparr[i];
            if(inparr[i]>=0&&inparr[i]<=r)
            {
                break;
            }
        }
    }
    countingsort(inparr, r, a);
    cout<<"The sorted array is:\n";
    for(int i=0;i<a;i++)
    {
        cout<<inparr[i]<<" ";
    }
    cout<<endl;
    return 0;
}