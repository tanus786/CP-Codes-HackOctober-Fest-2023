#include <stdio.h>
#include <limits.h>
int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int k;
    int count = 0;
    int min = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        count = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (count < min)
        {
            min = count;
        }
    }
    return min;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", solve(arr, 1, n - 1));

    return 0;
}
