#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll s = 0, ans = 0;
    vector<ll>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int back = arr.size()-1;
    while(s < back){
        if(arr[s]+arr[back]<=4){
            arr[back] += arr[s];
            s++;
        }
        else{
            back--;
            ans++;
        }
    }
    cout << ans+1 << "\n";
    return 0;
}