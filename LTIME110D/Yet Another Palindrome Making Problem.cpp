#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        string s;
         ll flag=0;
        cin>>s;
        vector<pair<char,int>>v;
        map<char,int>m;
        for (ll i = 0; i < n; i++)
        {
            v.push_back({s[i],i+1});
            m[s[i]]++;
        }
        sort(v.begin(),v.end());
        for (auto it:m)
        {
            if(it.second%2!=0)
            {
                flag=1;
                break;
            }
        }

        ll odd=0;
        ll even=0;
        for (ll i = 0; i < n-1; i++)
        {
            if(v[i].first==v[i+1].first)
            {
                if(v[i].second%2==0)
                even++;
                else
                odd++;
            }
            else
            {
                if(v[i].second%2==0)
                even++;
                else
                odd++;
                if(odd!=even)
                {
                    flag=1;
                    break;
                }
                odd=0;
                even=0;
            }
            if(i==n-2)
            {
                if(v[i+1].second%2==0)
                even++;
                else
                odd++;
                if(odd!=even)
                {
                    flag=1;
                    break;
                }
            }
        }

        if(flag)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;


    }
    return 0;
}
