#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll k = n;
    if(n % 2 == 0){
        ll ans = 0;
        while(n){
            if(n % 4 == 0 && n != 4){
                ans += 1;
                n-=2;
            }
            else if(n % 2 == 0){
                ans += n/2;
                n/=2;
                n--;
            }
            else{
                ans += 1;
                n--;
            }
        }
        cout << ans << "\n";
    }
    else{
        ll ans = 0;
        n--;
        while(n){
            if(n % 4 == 0 && n != 4){
                ans += 1;
                n-=2;
            }
            else if(n % 2 == 0){
                ans += n/2;
                n/=2;
                n--;
            }
            else{
                ans += 1;
                n--;
            }
        }
        cout << k - ans << "\n";
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