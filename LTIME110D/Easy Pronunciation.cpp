#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll n,count=0;
        cin>>n;
        string s;
        vector<int>v;
        cin>>s;
        for (ll i = 0; i < n; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                v.push_back(count);
                count=0;
            }
            else
            count++;
        }
        v.push_back(count);
        sort(v.begin(),v.end());
        if(v[v.size()-1]>=4)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;


    }
    return 0;
}
