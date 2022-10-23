#include <iostream>
using namespace std;

int main()
{
    int a;
    int min;

    cout << "how many number of pairs you want to enter: ";
    cin >> a;
    int gcd;
    int lcm;

    int arr[2 * a];
    int i;

    for (i = 0; i < 2 * a; i++)
    {
        cin >> arr[i];
    }
    i = 0;
    for (int j = 0; j < a; i++)
    {
        min = (arr[i] < arr[i + 1]) ? arr[i] : arr[i + 1];

        for (int k = 1; i <= min; i++)
        {
            if (arr[i] % k == 0 && arr[i + 1] % k == 0)
            {
                gcd = k;
            }
        }
        lcm = (arr[i] * arr[i + 1]) / gcd;

        cout << gcd << " " << lcm << endl;

        i = i + 2;
    }

    return 0;
}