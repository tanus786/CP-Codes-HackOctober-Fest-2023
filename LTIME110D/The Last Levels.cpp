#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x,y,z;
        cin >> x>>y>>z;
        ll d;
        if(x%3==0)
        d=x/3 -1;
        else
        d=x/3;
        cout<<((x*y)+(d*z))<<endl;

    }
    return 0;
}