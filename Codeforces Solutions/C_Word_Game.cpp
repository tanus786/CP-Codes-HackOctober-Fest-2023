#include<bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int l = 2*n;
    int k = 3*n;
    vector<string> v;
    map<string, int> mp;
    int a1 = 0, a2 = 0, a3 = 0;
    for(int i = 0; i < k; i++){
        string s;
        cin >> s;
        v.push_back(s);
        mp[s]++;
    }
    for(int i = 0; i < n; ++i){
        if(mp[v[i]] == 1) a1 += 3;
        else if(mp[v[i]] == 2) a1 += 1;
    }
    for(int i = n; i < l; ++i){
        if(mp[v[i]] == 1) a2 += 3;
        else if(mp[v[i]] == 2) a2 += 1;
    }
    for(int i = l; i < k; ++i){
        if(mp[v[i]] == 1) a3 += 3;
        else if(mp[v[i]] == 2) a3 += 1;
    }
    cout << a1 << " " << a2 << " " << a3 << "\n";
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
