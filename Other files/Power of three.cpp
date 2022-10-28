//c++ program to find whether the integer is a power of three or not
//Contributor: Shivam-3001

#include<bits/stdc++.h>
using namespace std;

string check(int n){
    if(n==0)
        return "No";
        
    while(n!=1){
        if(n%3!=0)
            return "No";
            
        n/=3;
    }
    return "Yes";
}
int main(){
    int n;
    cout<<"Enter an integer: "<<endl;
    cin>>n;

    cout<<check(n);
    return 0;
}
