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
    int n;
	cin >> n;
	vector<int>a(1005);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x] = i + 1;
	}
	int ans = -1;
	for(int i = 1; i <= 1000; i++) {
		for(int j = 1; j <= i; j++) {
			if(a[i] && a[j] && __gcd(i, j) == 1) {
				ans = max(ans, a[i] + a[j]);
			}
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