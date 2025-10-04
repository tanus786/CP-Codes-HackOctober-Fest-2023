#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        ll brr[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin>>brr[i];
        }
        sort(arr,arr+n);
        sort(brr,brr+n);
        vector<ll>v1;
        vector<ll>v2;
        for (ll i = (n-1)/2; i < n; i++)
        {
            v1.push_back(arr[i]);
        }
        for (ll i = (n-1)/2; i < n; i++)
        {
            v2.push_back(brr[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());

        vector<ll>main;
        for (ll i = 0; i < v1.size(); i++)
        {
            main.push_back(v1[i]+v2[i]);
        }
        sort(main.begin(),main.end());
        cout<<main[0]<<endl;




    }
    return 0;
}
