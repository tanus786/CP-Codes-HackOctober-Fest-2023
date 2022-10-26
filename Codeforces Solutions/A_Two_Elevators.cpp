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
    int a, b, c;
    cin >> a >> b >> c;
    if(abs(b-c) + abs(c-1) > abs(a-1)){
        cout << 1 << "\n";
        return;
    }
    if(abs(b-c) + abs(c-1) < abs(a-1)){
        cout << 2 << "\n";
        return;
    }
    else{
        cout << 3 << "\n";
        return;
    }
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