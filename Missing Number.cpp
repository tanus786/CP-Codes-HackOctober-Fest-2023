//C++ program to find the missing number in array of size n-1
//Contributed by : Shivam-3001

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    int arr[n-1];
    cout<<"Enter the elements of array "<<endl;
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    int sum=(n*(n+1))/2; //sum till n
    int sum1=0;  //for sum of all the elements in array
    for(int i=0; i<n-1; i++){
        sum1+=arr[i];
    }

    int ans=sum-sum1;
    cout<<"Missing number : "<<ans<<endl;
    return 0;
}
