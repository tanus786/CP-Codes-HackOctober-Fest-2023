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
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> st;
    for(int i = 0; i < n; i++){
        if((i==n-1 && s[i]=='0') || (s[i+1]!='0' && s[i]=='0')) st.insert(i-2);
    }
    string ans;
    for(int i = 0; i < n; i++){
        if(st.find(i) != st.end()){
            ans += 'a' + 10*(s[i]-'0') + (s[i+1]-'0')-1;
            i+=2;
        }
        else{
            ans += 'a' + (s[i]-'0'-1);
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