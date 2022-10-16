#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("inp1.in", "r", stdin);
    // freopen("inp1.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        long long ans = 1;
        for (int i = 0; i < 20; i++)
        {

            
            int cnt = ((x & (1 << i)) > 0);
            cnt += ((y & (1 << i)) > 0);
            cnt += ((z & (1 << i)) > 0);
            if (cnt == 1)
                {ans = 0;
                break;}
            else if (cnt == 3)
                ans *= 4;
        }
        cout << ans << endl;
    }
}