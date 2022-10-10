#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int res = a % b;
        a = b;
        b = res;
    }
    return a;
}

int main(){
    int a, b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;
    cout<<gcd(a, b)<<endl;
    return 0;
}