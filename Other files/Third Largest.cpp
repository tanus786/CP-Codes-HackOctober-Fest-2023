//C++ program to find the third largest element in array

#include<bits/stdc++.h>
using namespace std;


int Solve(int arr[], int n){
    map<int, int> mp;
	for(int i=0; i<n; i++){
	    mp[arr[i]]++;
    }
	int k=0;
	for(auto it: mp){
	    if(k==mp.size()-3)
	        return it.first;
	    k++;
	}
	return -1;
}

int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Third largest element : "<<Solve(arr, n);
    return 0;
}
