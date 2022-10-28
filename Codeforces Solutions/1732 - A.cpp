// problem link -: https://codeforces.com/contest/1732/problem/A

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = 
            tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld long double
#define ar array
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9+7;
const int inf = 1e9;
const ll linf = 1e18;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


// -------------------------------------------------- Main Code --------------------------------------------------

bool check(int n, vector<int> &arr) {
    int gcd = arr[0];
    for (auto i : arr) gcd = __gcd(gcd, i);
    return (gcd == 1);
}

bool check(int n, vi arr, int x) {
    arr[x] = __gcd(x+1, arr[x]);
    return check(n, arr);
}

void sol() {
    int n; cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (check(n, arr)) cout << 0 << endl;
    else if (check(n, arr, n-1)) cout << 1 << endl;
    else if (check(n, arr, n-2)) cout << 2 << endl;
    else cout << 3 << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t; 
    while (t--) {
        sol();
    }
    return 0;
}
