#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll count = 0;
        ll sum = 0;
        sort(arr, arr + n);
        for (ll i = 0; i < n; i++)
        {
            sum += arr[i];
            if (n - 1 >= sum)
            {

                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
