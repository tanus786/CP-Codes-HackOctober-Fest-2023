#include<bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    ll n, k, c;
    cin >> n >> k;
    map<ll, ll>mp;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(mp.find(i%k)!=mp.end()){
            mp[i%k] = max(mp[i%k], c);
        }
        else mp[i%k] = c;
    }
    for(auto x: mp) ans += x.second;
    cout << ans << "\n";
}


int main() {
	// your code goes here
	TURBO;
	ll testcase = 1;
	cin >> testcase;
	for(int tc = 1; tc <= testcase; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
	return 0;
}
