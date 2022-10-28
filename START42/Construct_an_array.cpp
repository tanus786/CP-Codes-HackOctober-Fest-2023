#include <bits/stdc++.h>
using namespace std;

// long long refr[1000001];

int main()
{
    // t, v are for test case inputs
    // s, u, w are for strings

    long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, t, v, x, y, z;
    long long num, val, check, count, sum, maxm, minm, mid, ans, fre, mfre;
    long long c0, c1;
    string s, u, w;
    cin >> t;
    v = t;
    // v = 1;

    while (v > 0)
    {
        v --;
        cin >> n;
        // cin >> s;

        // long long arr[n];
        // long long arr[n], ori[n], refr[n];
        // n = s.length ();

        // for (i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        // }

        // cout << "CASE" << " " << "#" << t - v << ":" << " "  

        if (n % 4 == 0)
        {
            for (i = 1; i <= (n / 2); i++)
            {
                cout << (i * (n - i)) << " " << ((n - i) * (i + 1)) << " ";
                cout << ((i + 1) * (n - i + 1)) << " " << ((n - i + 1) * i) << " ";
                i ++;
            }
            cout << endl;
        }
        else if (n % 2 == 0)
        {
            for (i = 1; i <= ((n - 2) / 2); i++)
            {
                cout << (i * (n - i)) << " " << ((n - i) * (i + 1)) << " ";
                cout << ((i + 1) * (n - i + 1)) << " " << ((n - i + 1) * i) << " ";
                i ++;
            }
            cout << (n / 2) << " " << (n / 2) + 1 << endl;
        }
        else
        {
            x = n;
            n --;
            if (x <= 3)
            {
                if (x == 1)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 2 << " " << 3 << " " << 6 << endl;
                }
            }
            else
            {
                if ((x - 1) % 4 == 0)
                {
                    for (i = 1; i <= (n / 2); i++)
                    {
                        if (i == 1)
                        {
                            cout << (i * (n - i) * x) << " " << ((n - i) * (i + 1)) << " ";
                            cout << ((i + 1) * (n - i + 1)) << " " << ((n - i + 1) * i) << " ";
                        }
                        else
                        {
                            cout << (i * (n - i)) << " " << ((n - i) * (i + 1)) << " ";
                            cout << ((i + 1) * (n - i + 1)) << " " << ((n - i + 1) * i) << " ";
                        }
                        i ++;
                    }
                    cout << x << endl;
                }
                else
                {
                    for (i = 1; i <= ((n - 2) / 2); i++)
                    {
                        if (i == 1)
                        {
                            cout << (i * (n - i) * x) << " " << ((n - i) * (i + 1)) << " ";
                            cout << ((i + 1) * (n - i + 1)) << " " << ((n - i + 1) * i) << " ";
                        }
                        else
                        {
                            cout << (i * (n - i)) << " " << ((n - i) * (i + 1)) << " ";
                            cout << ((i + 1) * (n - i + 1)) << " " << ((n - i + 1) * i) << " ";
                        }
                        i ++;
                    }
                    cout << (x / 2) << " " << (x / 2) + 1 << " " << x << endl;
                }
            }
        }
    }
    
    return 0;
}
