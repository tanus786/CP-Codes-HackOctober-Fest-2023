#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int s = 0, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        s += (b-a);
        maxi = max(maxi, s);
    }
    cout << maxi << "\n";
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