#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ar array
#define ll long long
#define ld long double


void solve(){
    ll n;
    cin >> n;
    if(n==3){
        cout << -1 << "\n";
        return;
    }
    if(n%2==0){
        for(int i = n; i >= 1; i--){
            cout << i << " ";
        }
        cout << "\n";
    }
    else{
        int k = n/2+1;
        for(int i = n; i > k; i--){
            cout << i << " ";
        }
        for(int i = 1; i <= k; i++){
            cout << i << " ";
        }
        cout << "\n";
    }
    return;
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