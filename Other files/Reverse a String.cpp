//c++ program to reverse a string
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: "<<endl;
    cin>>s;
    int n=s.size()-1;
    int l=0;
    while(l<n){
        char temp=s[l];
        s[l]=s[n];
        s[n]=temp;
        l++;
        n--;
    }
    cout<<"After Reversing the string: "<<s<<endl;
    return 0;
}
