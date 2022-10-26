#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n,k=0,i=0,s=0;
        cin >> n;
        s = n*(n+1)/2;
        while(pow(2,i)<=n){
            k += pow(2,i);
            i++;
        }
        cout << s-2*k << "\n";
    }
}