#include <bits/stdc++.h>
#define ll long long
#define fin(a,b,i) for(ll i=a;i<b;++i)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,j=0,k=0;
    cin>>n>>m;
    int a[n],b[m];
    fin(0,n,i){cin>>a[i];}
    fin(0,m,i){cin>>b[i];}
    fin(0,m,i){
        if(b[i]>=a[j]){j++;}
        if(j>=n){break;}
    }
    cout<<n-j;
    
    
    
    
    return 0;
}
