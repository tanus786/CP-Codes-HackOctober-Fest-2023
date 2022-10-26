#include<bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    int n, H, M;
    cin >> n >> H >> M;
    map<int, int>mp;
    for(int i = 0; i < n; ++i){
        int h, m;
        cin >> h >> m;
        mp[h*60 + m]++;
    }
    int t = 0;
    while(!mp[(H*60 + M + t) % (24*60)]){
        t++;
    }
    t %= (24*60);
    cout << t/60 << " " << t%60 << "\n";
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
