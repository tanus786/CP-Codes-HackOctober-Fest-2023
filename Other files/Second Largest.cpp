//C++ program to find the second largest element in array

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    map<int, int> mp;
	for(int i=0; i<n; i++){
        mp[arr[i]]++;
	}
	int ans=-1;
	int k=0;
	for(auto it: mp){
        if(k==mp.size()-2){
	        ans= it.first;
            break;
        }
	    k++;
	    
	}
	cout<<"Second largest element: "<<ans; 
    return 0;
}
