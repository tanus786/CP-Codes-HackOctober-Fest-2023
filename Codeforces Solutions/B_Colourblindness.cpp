#include<bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int flag = 0;
    for(int i = 0; i < n; ++i){
        if(s1[i] == 'G'){
            s1.replace(i, 1, "B");
        }
    }
    for(int i = 0; i < n; ++i){
        if(s2[i] == 'G'){
            s2.replace(i, 1, "B");
        }
    }
    if(s1 == s2) cout << "YES" << "\n";
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
