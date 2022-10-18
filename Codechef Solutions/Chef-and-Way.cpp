// Name of problem : Chef and Way
// Problem link : https://www.codechef.com/problems/CHRL4
// Contributed by Sanjoy Saha [github : SanjoySaha24]

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

#pragma comment(linker, "/STACK:36777216")

/*
  log(a[i]*a[j])=log(a[i])+log(a[j])
  use it in our solution
  Linear dp, look at last k places. and take the minimal one.
  You can do it fast with segment tree (log n), or more faster with linear algorithm
  that uses stacks. After it calculate answer modulo 10^9+7.
*/

struct nt
{
    long double x;
    int n;
};

nt dp[400000], tree[400000];
int n, k, l, r, sz;
int a[400000];
// build of segment tree
void build(int v, int l, int r)
{
    if (l == r)
    {
        tree[v].x = 1000000000;
        tree[v].n = l;
        return;
    }
    int m = (l + r) / 2;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    tree[v].x = 1000000000;
    tree[v].n = tree[v + v].n;
}

// update in segment tree
void upd(int v, int l, int r, int x, long double qr)
{
    if (l == x && r == x)
    {
        tree[v].x = qr;
        tree[v].n = l;
        return;
    }
    int m = (l + r) / 2;
    if (m >= x)
        upd(v + v, l, m, x, qr);
    else
        upd(v + v + 1, m + 1, r, x, qr);
    if (tree[v].x > qr)
    {
        tree[v].x = qr;
        tree[v].n = x;
    }
}
// get minimum on segment
nt get(int v, int l, int r, int ll, int rr)
{
    if (l == ll && r == rr)
        return tree[v];
    int m = (l + r) / 2;
    if (m >= rr)
        return get(v + v, l, m, ll, rr);
    else if (m < ll)
        return get(v + v + 1, m + 1, r, ll, rr);
    else
    {
        nt fir = get(v + v, l, m, ll, m);
        nt sec = get(v + v + 1, m + 1, r, m + 1, rr);
        if (fir.x > sec.x)
            return sec;
        else
            return fir;
    }
}

int main()
{

    ios ::sync_with_stdio(false);
    // Read Input
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sz = 1;
    while (sz < n)
        sz += sz;
    build(1, 0, sz - 1);
    upd(1, 0, sz - 1, 0, log(a[0]));
    // calculation of dp
    dp[0].n = -1;
    dp[0].x = log(a[0]);
    for (int i = 1; i < n; ++i)
    {
        r = i - 1;
        l = max(0, i - k);
        nt ans = get(1, 0, sz - 1, l, r);
        dp[i] = ans;
        dp[i].x += log(a[i]);
        upd(1, 0, sz - 1, i, dp[i].x);
    }
    // calculation finish answer
    long long res = 1;
    int pr = n - 1;
    while (pr >= 0)
    {
        res = res * (long long)a[pr] % MOD;
        pr = dp[pr].n;
    }
    cout << res << endl;
    return 0;
}
