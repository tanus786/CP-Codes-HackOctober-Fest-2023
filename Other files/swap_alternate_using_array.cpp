#include<bits/stdc++.h>
using namespace std;

void printa(int arr[] , int n){
    for (int i= 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void swapA(int arr[] , int size){
    for(int i=0;i<size;i+=2){
        if(i+1 < size){
            swap(arr[i] , arr[i+1]);
        }
    }
}

int main(){

int even[8] = {0,1,2,3,4,5,6,7};

swapA(even , 8);
printa(even , 8);
return 0;
}
