#include <iostream>
using namespace std;

int main()
{
    int tst;

    cin >> tst;

    while (tst--)
    {

        int len;

        cin >> len;

        if (len % 2 == 0)
        {
            for (int cntr = 1; cntr < (len + 2) / 2; cntr++)
            {
                cout << (6 * len) + 1 << " ";

                cout << (6 * len) - 1 << " ";
            }
        }

        else
        {
            cout << 1 << " ";
            for (int cntr = 1; cntr < (len + 1) / 2; cntr++)
            {
                cout << (6 * len) + 1 << " ";

                cout << (6 * len) - 1 << " ";
            }
        }

        cout << endl;
    }
    return 0;
}
