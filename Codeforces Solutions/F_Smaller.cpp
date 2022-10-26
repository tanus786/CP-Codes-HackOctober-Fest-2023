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
    map<char, ll>ms, mt;
    ms['a']++;
    mt['a']++;
    while(n--){
        ll d, k;
        string s;
        cin >> d >> k >> s;
        if(d == 1){
            for(int i = 0; i < s.size(); i++) ms[s[i]] += k;
        }
        else{
            for(int i = 0; i < s.size(); i++) mt[s[i]] += k;
        }
        if(mt.size() >= 2) cout << "YES" << "\n";
        else{
            if(ms.size() == 1){
                if(ms['a'] >= mt['a']) cout << "NO" << "\n";
                else cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }
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