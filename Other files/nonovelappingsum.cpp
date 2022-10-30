// CPP program to find Non-overlapping sum
#include <bits/stdc++.h>
using namespace std;
int findSum(int A[], int B[], int n)
{
	// Insert elements of both arrays
	unordered_map<int, int> hash;
	for (int i = 0; i < n; i++) {
		hash[A[i]]++;
		hash[B[i]]++;
	}

	// calculate non-overlapped sum
	int sum = 0;
	for (auto x: hash)
		if (x.second == 1)
			sum += x.first;
	
	return sum;
}

// driver code
int main()
{
	int A[] = { 5, 4, 9, 2, 3 };
	int B[] = { 2, 8, 7, 6, 3 };
	
	// size of array
	int n = sizeof(A) / sizeof(A[0]);

	// function call
	cout << findSum(A, B, n);
	return 0;
}
