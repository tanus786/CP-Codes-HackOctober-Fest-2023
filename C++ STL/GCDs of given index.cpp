// C++ Program to find GCD of a number in a given Range
// using segment Trees
#include <bits/stdc++.h>
using namespace std;

// To store segment tree
int* st;

/* A recursive function to get gcd of given
	range of array indexes. The following are parameters for
	this function.

	st --> Pointer to segment tree
	si --> Index of current node in the segment tree.
Initially 0 is passed as root is always at index 0 ss &
se --> Starting and ending indexes of the segment
				represented by current node, i.e.,
st[index] qs & qe --> Starting and ending indexes of
query range */
int findGcd(int ss, int se, int qs, int qe, int si)
{
	if (ss > qe || se < qs)
		return 0;
	if (qs <= ss && qe >= se)
		return st[si];
	int mid = ss + (se - ss) / 2;
	return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
				findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

// Finding The gcd of given Range
int findRangeGcd(int ss, int se, int arr[], int n)
{
	if (ss < 0 || se > n - 1 || ss > se) {
		cout << "Invalid Arguments"
			<< "\n";
		return -1;
	}
	return findGcd(0, n - 1, ss, se, 0);
}

// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
int constructST(int arr[], int ss, int se, int si)
{
	if (ss == se) {
		st[si] = arr[ss];
		return st[si];
	}
	int mid = ss + (se - ss) / 2;
	st[si]
		= __gcd(constructST(arr, ss, mid, si * 2 + 1),
				constructST(arr, mid + 1, se, si * 2 + 2));
	return st[si];
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
int* constructSegmentTree(int arr[], int n)
{
	int height = (int)(ceil(log2(n)));
	int size = 2 * (int)pow(2, height) - 1;
	st = new int[size];
	constructST(arr, 0, n - 1, 0);
	return st;
}

// Driver program to test above functions
int main()
{
	int a[] = { 2, 3, 6, 9, 5 };
	int n = sizeof(a) / sizeof(a[0]);

	// Build segment tree from given array
	constructSegmentTree(a, n);

	// Starting index of range. These indexes are 0 based.
	int l = 1;

	// Last index of range.These indexes are 0 based.
	int r = 3;
	cout << "GCD of the given range is:";
	cout << findRangeGcd(l, r, a, n) << "\n";

	return 0;
}
