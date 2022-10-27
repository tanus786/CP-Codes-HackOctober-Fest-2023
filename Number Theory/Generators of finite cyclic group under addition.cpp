// A simple C++ program to find all generators
#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

// Print generators of n
int printGenerators(unsigned int n)
{
	// 1 is always a generator
	cout << "1 ";

	for (int i=2; i < n; i++)

		// A number x is generator of GCD is 1
		if (gcd(i, n) == 1)
			cout << i << " ";
}

// Driver program to test above function
int main()
{
	int n = 10;
	printGenerators(n);
	return 0;
}
