//C++ program to find whether a number is palindrome or not
//Contibutor : Shivam-3001

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int temp=n; //for comparing with the reversed number
    int rev=0;  //to store the reversed number
    while(n>0){
        int rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    if(temp==rev)
        cout<<"Palindrome Number";
    else
        cout<<"Not a Palindrome Number";
    return 0;
}
