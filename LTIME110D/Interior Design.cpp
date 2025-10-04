#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a,b,c,d;
        cin >> a>>b>>c>>d;
        ll e=a+b;
        ll f=c+d;
        if(e>f)
        cout<<f<<endl;
        else
        cout<<e<<endl;
    }
    return 0;
}