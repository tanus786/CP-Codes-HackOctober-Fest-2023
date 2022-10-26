#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve(){
    ll n, x;
    cin >> n >> x;
    ll ans = 0, kount = 0;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    if(n > x){
        ans = n;
    }
    else{
        for(int i = 0; i < n; ++i){
            kount = x/v[i];
            ans += kount;
        }
    }
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