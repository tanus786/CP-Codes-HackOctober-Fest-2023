#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n;
    cin >> n;
    if(n%2) cout << ((n+1)/2)*(-1);
    else cout << n/2 << "\n";
}