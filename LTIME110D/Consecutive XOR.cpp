#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        bool iszer = false;
        char c = a[0];
        bool isB = false;
        for (int i = 0; i < b.size() - 1; i++)
        {
            if (b[i] == b[i + 1])
                isB = true;
        }
        if (c == '0')
        {
            for (int i = 1; i < a.size(); i++)
            {
                if (a[i] == '1')
                    iszer = true;
            }
            if (iszer&isB)
                cout << "YES" << endl;
            else
            {
                if (a == b)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        else if (c == '1')
        {
            for (int i = 1; i < a.size(); i++)
            {
                if (a[i] == '0')
                    iszer = true;
            }
            if (isB)
            {
                cout << "YES" << endl;
            }
            else
            {

                if (a == b)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}
