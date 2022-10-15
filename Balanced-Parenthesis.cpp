// Balanced Parenthesis using cpp
// Contributed by Sanjoy Saha [github : SanjoySaha24]

#include <iostream>
using namespace std;
int main()
{
    int st[16], i, j, k, temp;
    cout << "enter 5 elements only to sort n:-";
    for (i = 0; i < 5; i++)
    {
        cin >> st[i];
    }
    for (i = 1; i < 5; i++)
    {
        for (j = i; j >= 1; j--)
        {
            if (st[j] < st[j - 1])
            {
                temp = st[j];
                st[j] = st[j - 1];
                st[j - 1] = temp;
            }
            else
                break;
        }
    }
    cout << "sorted array n " << endl;
    for (k = 0; k < 5; k++)
        cout << st[k] << endl;
}