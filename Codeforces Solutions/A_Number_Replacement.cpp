#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    string s;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    map<int, set<char>>mp;
    for(int i = 0; i < n; i++){
        mp[a[i]].insert(s[i]);
    }
    for(auto &x: mp){
        if(x.second.size() > 1){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}


int main(){
    int tt = 1;
    cin >> tt;
    for(int i = 0; i < tt; i++){
        solve();
    }
}