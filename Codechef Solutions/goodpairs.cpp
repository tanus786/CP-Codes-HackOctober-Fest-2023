#include <bits/stdc++.h>

using namespace std;

long long findFactorial(long long n)
{
    if (n == 1)
        return (1);
    if (n == 2)
        return (2);
    else
        return (n * findFactorial(n - 1));
}

unsigned long long findNcR(long long n)
{

    if (n == 2)
    {
        return 1;
    }
    else
        return (findFactorial(n) / (findFactorial(n - 2) * findFactorial(2)));
}

int main()
{
    int tst;

    cin >> tst;

    while (tst--)
    {
        long long len;

        cin >> len;

        long long count = 0;
        
        unsigned long long ans = 0;

        long long arr[len];

        for (int cntr = 0; cntr < len; cntr++)
        {

            cin >> arr[cntr];
        }

        sort(arr, arr + len);

        for (int cntr = 1; cntr < len; cntr++)
        {

            if (arr[cntr - 1] != arr[cntr] && count != 0)
            {

                count++;

                ans = ans + findNcR(count);

                count = 0;
                continue;
            }

            else if (arr[cntr - 1] != arr[cntr])
            {

                count = 0;

                continue;
            }

            count++;
        }

        if (count != 0)
        {

            count++;

            ans = ans + findNcR(count);

            count = 0;
        }

        cout << ans << endl;
    }

    return 0;
}
