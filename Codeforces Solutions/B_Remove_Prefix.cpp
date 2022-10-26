#include<bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int>a(n);
    set<int>s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; --i){
        if(s.count(a[i])){
            ans = i + 1;
            break;
        }
        else{
            s.insert(a[i]);
        }
    }
    cout << ans << "\n";
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
