// problem link -: https://codeforces.com/contest/1732/problem/D2

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

set<int> st;
map<int, int> last;
map<int, set<int>> cache, del;

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int q; cin >> q;
    while (q--) {
        char ch; cin >> ch;
        int x; cin >> x;
        if (ch == '+') {
            st.insert(x);
            for (auto i : cache[x]) {
                if (del[i].count(x)) del[i].erase(x);
            }
        }
        else if (ch == '-') {
            st.erase(x);
            for (auto i : cache[x]) del[i].insert(x);
        }
        else {
            if (del[x].size()) cout << *del[x].begin() << endl;
            else {
                int ans = (last[x]==0?x:last[x]);
                while (st.count(ans)) cache[ans].insert(x), ans += x;
                last[x] = ans;
                cout << ans << endl;
            }
        }
    }

    return 0;
}
