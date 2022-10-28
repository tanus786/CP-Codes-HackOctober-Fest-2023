#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    int maxx=INT_MIN;
    int minn=INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]>maxx)
            maxx=arr[i];
    	        
    	if(arr[i]<minn)
    	   minn=arr[i];
    }
    cout<<"Addition of maximum and minimum: "<<(minn+maxx);
    return 0;
}
