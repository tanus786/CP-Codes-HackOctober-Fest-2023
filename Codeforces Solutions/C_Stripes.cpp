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
    char a[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin>>a[i][j];
        }
    }
    for (int i = 0; i < 8; i++){
        ll cr=0;
        for (int j = 0; j < 8; j++)
        {
            if(a[i][j]=='R')cr++;
        }
        if(cr==8){
            cout << "R\n";
            return;
        }
    }
    for (int i = 0; i < 8; i++){
        ll cr=0;
        for (int k = 0; k < 8; k++)
        {
            if(a[k][i]=='B')cr++;
        }
        if(cr==8){
            cout << "B\n";
            return;
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
