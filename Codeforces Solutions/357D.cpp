/*  https://codeforces.com/contest/357/problem/B  */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n,m; cin>>n>>m;
    ll a[m][3];
    for(ll i=0;i<m;i++){
        for(ll j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    ll ans[n+1]={0};
    ans[a[0][0]] = 1;
    ans[a[0][1]] = 2;
    ans[a[0][2]] = 3;
    for(ll i=1;i<m;i++){
        if(ans[a[i][0]]!=0){
            if(ans[a[i][0]]==1){ans[a[i][1]]=2; ans[a[i][2]]=3;}
            else if(ans[a[i][0]]==2){ans[a[i][1]]=1; ans[a[i][2]]=3;}
            else{ans[a[i][1]]=1; ans[a[i][2]]=2;}
        }
        else if(ans[a[i][1]]!=0){
            if(ans[a[i][1]]==1){ans[a[i][0]]=2; ans[a[i][2]]=3;}
            else if(ans[a[i][1]]==2){ans[a[i][0]]=1; ans[a[i][2]]=3;}
            else{ans[a[i][0]]=1; ans[a[i][2]]=2;}
        }
        else if(ans[a[i][2]]!=0){
            if(ans[a[i][2]]==1){ans[a[i][0]]=2; ans[a[i][1]]=3;}
            else if(ans[a[i][2]]==2){ans[a[i][0]]=1; ans[a[i][1]]=3;}
            else{ans[a[i][0]]=1; ans[a[i][1]]=2;}
        }
        else{
            ans[a[i][0]]=1; ans[a[i][1]]=2; ans[a[i][2]]=3;
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
