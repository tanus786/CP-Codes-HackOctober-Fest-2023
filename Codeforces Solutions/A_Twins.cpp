#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll s = 0, ans = 0, s1 = 0;
    vector<ll>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    for(int i = 0; i < n; i++){
        s1 += arr[i];
        ans++;
        if(s1 > s/2) break;
    }
    cout << ans << "\n";
    return 0;
}