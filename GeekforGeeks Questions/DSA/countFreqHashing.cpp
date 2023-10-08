#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the length of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    int q;
    cout<<"Enter for how many numbers you have to check the frequency:";
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number for which you have to check the frequency:";
        cin>>number;
        cout<<hash[number]<<endl;

    }
    return 0;
}