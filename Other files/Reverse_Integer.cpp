//C++ program to reverse an integer
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter an integer: "<<endl;
    cin>>n;
    int temp=n;
    int rev=0;
    while(n>0){
        int rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }

    cout<<"Reverse of "<<temp<<" is "<<rev<<endl;
    return 0;
}
