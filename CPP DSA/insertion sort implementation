#include <iostream>
#include <algorithm>
using namespace std;

void iSort(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
	
    int arr[]={50,20,40,60,10,30};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	iSort(arr,n);
	
	for(auto x: arr)
	    cout<<x<<" ";
}
