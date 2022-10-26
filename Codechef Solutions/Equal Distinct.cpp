#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    map<ll,ll> mp;
    for(auto &it:v)mp[it]++;
    ll count=0;
    for(auto &it:mp){
        if(it.second==1)count++;
    }
    if((n%2==1 && count==n))cout<<"no"<<endl;
    else cout<<"yes"<<endl;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
       
