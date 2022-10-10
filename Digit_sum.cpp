/*
Added digit sum code using recursion in c++
Author:Sonali Rao

*/

#include<bits/stdc++.h>
using namespace std;
int digitsum(int n){
    if(n==0) return 0;
    return digitsum(n/10)+n%10;
}
/*
Sonali Rao

*/
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<digitsum(n);
    }
}