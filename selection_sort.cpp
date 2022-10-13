#include <iostream>
#include <climits>
using namespace std;
void selectionsort(int *a, int n)
{
    int min = INT_MAX, k;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                k = j;
            }
            if (j == n - 1)
            {
                int t = a[i];
                a[i] = a[k];
                a[k] = t;
                min = INT_MAX;
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
    selectionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
}