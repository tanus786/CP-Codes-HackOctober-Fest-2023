#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/kartik/algo/debug.h"
#else
#define debug(...) 23032002
#endif

typedef long long int ll;
const int mod = 1000000007, mod2 = 998244353;
const ll inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mx = a[0], mn = a[0];
    string ans = "YES\n";
    for (int i = 1; i < n; ++i) {
        if (a[i] >= mx || a[i] <= mn) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        } else {
            ans = "NO\n";
            break;
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int tt; cin >> tt;
    while(tt--) solve();

    // for(int i = 1; i <= tt; ++i) {
        // cout << "Case #" << i << ": ";
        // solve();
    // }

    return 0;
}
