#include <iostream>

using namespace std;

int main()
{

    int tst;

    cin >> tst;

    while (tst--)
    {
        int n, k;

        cin >> n >> k;

        if (n >= (k * (k + 1)) / 2)
        {
            cout << "YES" << endl;
        }

        else
            cout << "NO" << endl;
    }

    return 0;
}