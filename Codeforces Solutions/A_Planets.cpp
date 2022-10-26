#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long int INF = 1e18;

void solution(){
    ll n, c;
    cin >> n >> c;
    vector<ll>a(n);
    map<ll,ll>mp;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for(auto &x:mp){
        ans += min(c, x.second);
    }
    cout << ans << "\n";
}


int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){
        solution();
    }
    return 0;
}
