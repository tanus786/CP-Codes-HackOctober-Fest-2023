#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t ;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        while(n--){
            int side,coin,q;
            cin>>side>>coin>>q;
            int ans = coin/2;
            if(side==q)cout << ans <<'\n';
            else cout << coin-ans <<'\n';
        }
    }
    return 0;
}
