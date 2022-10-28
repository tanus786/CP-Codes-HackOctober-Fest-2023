#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of elements of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    map<int, int> element;
    for(int i=0; i<n; i++){
        element[arr[i]]++;
    }
    int maj=n/2;
    int ans=-1;
    for(auto it: element){
        if(it.second > maj)
            ans = (it.first);
    }
    
    cout<<"Majority Element : "<<ans;

    return 0;
}
