#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll>a(n);
    ll sumo = 0, sume = 0;
    ll ce = 0, co = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(a[i]%2){
            sumo += a[i];
            co++;
        }
        else{
            sume += a[i];
            ce++;
        }
    }
    while(q--){
        ll type, x;
        cin >> type >> x;
        if(type == 0){
            sume += x*ce;
            if(x%2){
                co += ce;
                ce = 0;
            }
        }
        else{
            sumo += x*co;
            if(x%2){
                ce += co;
                co = 0;
            }
        }
        cout << sume + sumo << "\n";
    }
}


int main(){
    int tt = 1;
    cin >> tt;
    for(int i = 0; i < tt; i++){
        solve();
    }
}