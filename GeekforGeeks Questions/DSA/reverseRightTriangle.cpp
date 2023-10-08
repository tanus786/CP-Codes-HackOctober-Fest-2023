#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        for(int j=0;j<t-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}