#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int space=2*(t-1);
    for (int i=1;i<=t;i++){
        for (int j=1;j<=i;j++){
            cout << j;
        }
        for (int j=1;j<=space;j++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout << j;
        }
        cout<<endl;
        space-=2;
    }
    return 0;
}