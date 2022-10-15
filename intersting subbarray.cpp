#include <iostream>

#include <cmath>

using namespace std;

int main()
{

    int tst;

    cin >> tst;

    while (tst--)
    {

        int len;

        cin >> len;

        long arr[len];

        long arr2[len];

        long max, min;

        for (int cntr = 0; cntr < len; cntr++)
        {
            cin >> arr[cntr];

            if (cntr == 0)
            {
                max = min = arr[cntr];
            }

            if (arr[cntr] < min)
                min = arr[cntr];

            if (arr[cntr] > max)
                max = arr[cntr];
        }

        if (min < 0 && max > 0)
        {
            cout << min * max << " ";

            if (max > abs(min))
                cout << max * max << endl;
            else
                cout << min * min << endl;
        }

        else if (max >= 0 && min >= 0)
        {
            cout << min * min << " " << max * max << endl;
        }

        else if (max < 0 && min < 0)
        {
            cout << max * max << " " << min * min << endl;
        }
    }

    return 0;
}