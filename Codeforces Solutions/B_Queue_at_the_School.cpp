#include <bits/stdc++.h>
using namespace std;
#define TURBO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int main(){
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    while (t--){
        for (int i = 1; i < n; ++i){
            if (s[i] == 'G' && s[i-1] == 'B'){
                s[i] = 'B';
                s[i-1] = 'G';
                i++;
            }
        }
    }
    cout << s << endl;
    return 0;
}