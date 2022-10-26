#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ar array
#define ll long long
#define ld long double


void solve(){
    string a, b;
    cin >> a >> b;
    int sza = a.size();
    int szb = b.size();
    if(a==b){
        cout << "=" << "\n";
        return;
    }
    if(a[sza-1]==b[szb-1]){
        if(a[sza-1]=='S'){
            if(sza>szb) cout << "<" << "\n";
            else cout << ">" << "\n";
        }
        else if(a[sza-1]=='L'){
            if(sza<szb) cout << "<" << "\n";
            else cout << ">" << "\n";
        }
        else cout << "=" << "\n";
        return;
    }
    if(a[sza-1]=='L') cout << ">" << "\n";
    else if(a[sza-1]=='S') cout << "<" << "\n";
    else if(a[sza-1]=='M'){
        if(b[szb-1]=='S') cout << ">" << "\n";
        else cout << "<" << "\n";
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