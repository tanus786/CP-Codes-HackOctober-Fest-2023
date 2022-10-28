// C++ program to find maximum product of an increasing
// subsequence of size 3
#include <bits/stdc++.h>
using namespace std;

// Returns maximum product of an increasing subsequence of
// size 3 in arr[0..n-1]. If no such subsequence exists,
// then it returns INT_MIN
long long int maxProduct(int arr[], int n)
{
	int result = INT_MIN;
	// T.C : O(n^3)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				result
					= max(result, arr[i] * arr[j] * arr[k]);
			}
		}
	}

	return result;
}

// Driver Program
int main()
{
	int arr[] = { 10, 11, 9, 5, 6, 1, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxProduct(arr, n) << endl;
	return 0;
}
