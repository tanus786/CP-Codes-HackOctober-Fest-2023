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

    int maxx=INT_MIN;
    for(int i=0; i<n; i++)
        if(arr[i]>maxx)
            maxx=arr[i];

    cout<<"Maximum element: "<<maxx<<endl;
    return 0;
}