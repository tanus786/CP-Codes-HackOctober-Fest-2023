#include<iostream>
using namespace std;

int countGoodSubarrays(int arr[], int n)
{
    int csum[n+1];
    csum[0]=0;//csum of all elements before index 0=0

    for(int i=1; i<=n; i++)
    {
        csum[i]=csum[i-1]+arr[i-1];
    }

    int cnt=0;
    for(int i=0; i<=n-1; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int sum_ij=(csum[i]-csum[j]+n);

            if(sum_ij%n==0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}


int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    cout<<countGoodSubarrays(arr,n);

    return 0;
}
