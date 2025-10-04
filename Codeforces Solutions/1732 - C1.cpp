// problem link -: https://codeforces.com/contest/1732/problem/C1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void sol(int number) {
    int n, q; cin >> n >> q;
    // if (number == 118) cout << n << endl;
    vector<int> arr(1), pos(1);
    int array[n+1]; for (int i = 1; i <= n; i++) {
        cin >> array[i];
        // if (number == 118) cout << array[i] << " ";
        if (array[i] != 0) {
            arr.push_back(array[i]);
            pos.push_back(i);
        }
    }
    // if (number == 118) cout << endl;

    int pref[n+1] = {0}, prefxor[n+1] = {0}, zero[n+1] = {0};
    for (int i = 1; i < arr.size(); i++) pref[i] = (pref[i-1]+arr[i]), prefxor[i] = (prefxor[i-1]^arr[i]);

    for (int i = 1; i <= n; i++) {
        zero[i] += zero[i-1] + (array[i]==0);
    }

    while (q--) {
        int left, right; cin >> left >> right;

        int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
        int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin() - 1;

        if (l > r) {cout << l << " " << l << endl; continue;}
        
        auto get = [&](int i, int j) {return (pref[j]-pref[i-1]) - (prefxor[j]^prefxor[i-1]);};
        int sum = get(l, r);
        if (sum == 0) {/*if (t <= 6 || number == 118) */cout << l << " " << l << endl; continue;}

        int ii = l, jj = r;
        for (int i = l; i <= min(l+35, r); i++) {
            for (int j = r; j >= max(l, r-35); j--) {
                if (j > i) {
                    if (get(i, j) == get(l, r)) {
                        if (((j+zero[pos[j]])-(i+zero[pos[i]])) < ((jj+zero[pos[jj]])-(ii+zero[pos[ii]]))) jj = j, ii = i;
                    }
                }
            }
        }
        /*if (t <= 6 || number == 118) */cout << ii+zero[pos[ii]]<< " " << jj+zero[pos[jj]] << endl;
    }
}

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t; 
    for (int i = 1; i <= t; i++) sol(i);
    return 0;
}
