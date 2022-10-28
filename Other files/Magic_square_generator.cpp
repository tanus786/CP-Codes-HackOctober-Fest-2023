/*
 * This program constructs a magic square matrix given the dimension as input.
 */
#include <bits\stdc++.h>

using namespace std;

int main()
{
    int i, j, n;

    cout << "Enter value of n: ";
    cin >> n;

    int mat[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }

    i = n / 2;
    j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {

            if (j == n)
                j = 0;

            if (i < 0)
                i = n - 1;
        }

        if (mat[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            mat[i][j] = num++;

        j++;
        i--;
    }

    printf("The Magic Square for n=%d: \nSum of each row or column %d:\n\n", n, n * (n * n + 1) / 2);
    cout << "Sum of each row or column= " << (n * (n * n + 1) / 2);
    cout << "\nThe Magic Square for n= " << n << ": \n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d  ", mat[i][j]);
        }
        cout << endl;
    }

    return 0;
}

// This code is contributed by Omkar Jahagirdar (Github: omkar3602)