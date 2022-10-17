// Name of problem : Two Buttons
// Problem link : https://codeforces.com/problemset/problem/520/B
// Contributed by Sanjoy Saha [github : SanjoySaha24]

#include <iostream>
using namespace std;

int main()
{
    int n, m, w(0);
    cin >> n >> m;
    while (n != m)
    {
        if (m > n)
            if (m % 2 == 0) m /= 2, w++;
            else m++, w++;
        else if (n > m) m++, w++;
    }
    cout << w << endl;
    return 0;
}
