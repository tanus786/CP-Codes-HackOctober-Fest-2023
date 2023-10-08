#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    //space
    for (int i=0;i<t;i++){
        for (int j=0;j<=t-i-1;j++){
            cout<<" ";
        }
        for (int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for (int j=0;j<t-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }

    //reverse triangle
    for (int i=0;i<=t;i++){
        for (int j=0;j<i;j++){
            cout<<" ";
        }
        for (int j=0;j<2*t-(2*i+1);j++){
            cout<<"*";
        }
        for (int j=0;j<i;j++){
            cout<<" ";
        }
        cout << endl;
    }
    return 0;
    
}