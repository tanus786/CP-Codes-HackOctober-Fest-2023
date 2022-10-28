#include<bits/stdc++.h>
using namespace std;
int countf(int ind, int sum, int n, int arr[]){
if(ind==n){
    if(sum==0){
        return 1;
    }
    else return 0;
}
int left=0;
int right=0;
// picking
if(arr[ind]<=sum){
    sum-=arr[ind];
    left=countf(ind, sum, n, arr);
    sum+=arr[ind];
}
//moving to next index                          // 1+1+1+1
right=countf(ind+1,sum,n,arr);                  // 1+1+2
return left+right;                              //2+2
}                                               // 1+3
int main(){
   int arr[]={1,2,3};
int n=sizeof(arr)/sizeof(arr[0]);

cout << countf(0,4,n,arr);
}
