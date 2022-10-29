// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;

// A Dynamic Programming based
// solution that uses table P[][]
// to calculate the Permutation
// Coefficient
#include<bits/stdc++.h>

// Returns value of Permutation
// Coefficient P(n, k)
int permutationCoeff(int n, int k)
{
	int P[n + 1][k + 1];

	// Calculate value of Permutation
	// Coefficient in bottom up manner
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= std::min(i, k); j++)
		{
			// Base Cases
			if (j == 0)
				P[i][j] = 1;

			// Calculate value using
			// previously stored values
			else
				P[i][j] = P[i - 1][j] +
						(j * P[i - 1][j - 1]);

			// This step is important
			// as P(i,j)=0 for j>i
			P[i][j + 1] = 0;
		}
	}
	return P[n][k];
}


// Driver Code
int main()
{
	int n = 10, k = 2;
	cout << "Value of P(" << n <<" " << k<< ") is " << permutationCoeff(n, k);

	return 0;
}

// This code is contributed by code_hunt.
