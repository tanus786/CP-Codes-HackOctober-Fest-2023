// problem link -: https://codeforces.com/contest/1732/problem/D1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

map<int, int> last;
set<int> st;

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q; cin >> q;
    while (q--) {
        char ch;
        int x; cin >> ch >> x;
        
        if (ch == '?') {
            int ans = (last[x]==0?x:last[x]);
            while (st.count(ans)) ans += x;
            last[x] = ans;
            cout << ans << endl;
        }
        else {
            st.insert(x);
        }
    }
    return 0;
}
