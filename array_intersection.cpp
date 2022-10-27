#include<iostream>
#include <algorithm>

using namespace std;

printCommonArray(int c[], int n)
{
    cout<<"[";
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            cout<<c[i];
        }

        else
        {
            cout<<c[i]<<", ";
        }
    }

    cout<<"]";
}

void printIntersection(int a[], int b[], int n)
{
    int k=0;
    int common[n]={0};

    int a_length=n;
    int b_length=n;

    for(int i=0; i<a_length; i++)
    {
        int j=0;
        while(j<b_length)
        {
            if(a[i]==b[j])
            {
                common[k++]=a[i];

                //then swap with the last element and reduce array size by 1 and check till that alone
                swap(b[j],b[b_length-1]);
                b_length=b_length-1;
                break;
            }
            j++;
        }
    }

    //sort common array
    sort(common, common+k);
    printCommonArray(common, k);
}


int main()
{
    int n;
    cin>>n;

    int a[n], b[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }

    int c[n];
    printIntersection(a,b,n);

    return 0;
}
