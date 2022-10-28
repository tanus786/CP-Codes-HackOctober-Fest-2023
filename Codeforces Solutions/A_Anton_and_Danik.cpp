#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ac = 0, dc = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') ac++;
        else dc++;
    }
    if(ac > dc) cout << "Anton" << "\n";
    else if(dc > ac) cout << "Danik" << "\n";
    else cout << "Friendship" << "\n";
}


int main() {
	// your code goes here
	TURBO;
	ll testcase = 1;
	// cin >> testcase;
	for(int tc = 1; tc <= testcase; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
	return 0;
}