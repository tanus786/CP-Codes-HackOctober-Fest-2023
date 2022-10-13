//C++ program to find the minimum element in an array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements in array: "<<endl;
    cin>>n;
    int  arr[n];
    cout<<"Enter the elements of array : "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int minn=INT_MAX;
    for(int i=0; i<n; i++)
        if(arr[i]<minn)
            minn=arr[i];

    cout<<"Minimum element: "<<minn<<endl;
    return 0;
}