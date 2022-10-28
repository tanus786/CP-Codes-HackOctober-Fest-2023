#include<iostream>
#include <algorithm>    // std::sort
using namespace std;

void sortTriplet(int a, int b, int c)
{
    int highest=max(max(a,b),c);
    int lowest=min(min(a,b),c);
    int middle=a+b+c-highest-lowest;
    cout<<lowest<<", "<<middle<<" and "<<highest<<endl;
}

void findAllTripletsWithTargetSum(int arr[], int n, int target)
{

        for(int i=0; i<=n-3;i++)
        {
            for(int j=i+1; j<=n-2; j++)
            {
                for(int k=j+1; k<=n-1; k++)
                {
                    int triplet_sum=arr[i]+arr[j]+arr[k];
                    if(triplet_sum==target)
                    {
                        sortTriplet(arr[i], arr[j], arr[k]);
                        //cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k]<<endl;
                    }
                }

            }

        }
}


int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int target;
    cin>>target;

    //sort(arr, arr + n);
    findAllTripletsWithTargetSum(arr,n,target);

    return 0;
}
