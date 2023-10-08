#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        for (int j=0;j<=i;j++){
            if ((i+j) % 2==0){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }

        cout<<endl;
    }
    return 0;
}