#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,m;
int main(){
    ll mod=1e9+7;
    cin>>t;
    while(t--){
        cin>>n;
        set<ll> s;
        for(ll i=0;i<4*n;i++) s.insert(i);
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a<4*n) s.erase(s.find(a));
        }
        ll b=2*n+1;
        while(b--){
            cout<<*s.begin()<<'\n';
            s.erase(s.begin());
            ll c;
            cin>>c;
            if(c<0 || s.find(c)!=s.end()){
                break;
            }
            s.insert(c);
        }
    }
}
