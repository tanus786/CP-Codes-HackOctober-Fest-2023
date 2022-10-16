#include <iostream>

using namespace std;

int main()
{

    int tst;
    cin >> tst;
    while (tst--)
    {
        int n, p, x, y;

        cin >> n >> p >> x >> y;

        int time = 0,
            inp;

        for (int cntr = 0; cntr < n; cntr++)
        {
            cin >> inp;

            if (cntr < p)
            {
                if (inp == 0)
                {
                    time = time + x;
                }

                else if (inp == 1)
                {
                    time = time + y;
                }
            }
        }

        cout << time << endl;
    }
    return 0;
}