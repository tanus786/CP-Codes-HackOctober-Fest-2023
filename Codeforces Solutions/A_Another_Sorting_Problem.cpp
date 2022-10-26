#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

bool compare(pair<string, int>ms, pair<string, int>ns){
    string p = ms.first;
    string q = ns.first;
    for(int i = 0; i < p.size(); i++){
        if(p[i] != q[i]){
            if(i % 2 == 0) return p[i] < q[i];
            return p[i] > q[i];
        }
    }
    return true;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    pair<string, int> mp[n];
    for(int i = 0; i < n; ++i){
        cin >> mp[i].first;
        mp[i].second = i;
    }
    sort(mp, mp+n, compare);
    for(int i = 0; i < n; i++){
        cout << mp[i].second + 1 << " ";
    }
    cout << "\n";
}


int main() {
	// your code goes here
	TURBO;
	ll testcase = 1;
	// cin >> testcase;
	for(int tc = 1; tc <= testcase; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
	return 0;
}