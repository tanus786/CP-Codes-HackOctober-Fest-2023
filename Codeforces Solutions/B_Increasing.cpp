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
    ll n;
    cin >> n;
    ll count = 0;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(a.size() == 1){
        cout << "YES" << "\n";
        return;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1]){
            count++;
        }
    }
    if(count == n-1){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
    
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