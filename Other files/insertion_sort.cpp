#include <iostream>
using namespace std;
void insertionsort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            int k = a[i];
            int l;
            for (l = i; l >= 0; l--)
            {
                if (k < a[l - 1] && l != 0)
                {
                    a[l] = a[l - 1];
                }
                else
                {
                    a[l] = k;
                    break;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
}