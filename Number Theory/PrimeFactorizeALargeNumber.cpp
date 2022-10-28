#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prime_factorize(ll x)
{
    vector<ll> ans;

    while(x%2 == 0) {
        ans.push_back(2);
        x = x/2;
    }

    // n must be odd at this point. So we can skip one element (Note i = i + 2)
    ll root = sqrt(x);
    for (ll i=3; i<=root; i+=2) {
        while (x%i == 0) {
            ans.push_back(i);
            x = x/i;
        }
    }

    if (x > 2) {
        ans.push_back(x);
    }

    return ans;
}

int main()
{
    ll x = 989176015421738214;

    vector<ll> pf = prime_factorize(x);

    for(auto y: pf) {
        cout << y << " ";
    }

    return 0;
}
