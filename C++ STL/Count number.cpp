// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function that count set bits
int countSetBits(int n)
{
	int count = 0;
	while (n > 0) {
		count++;
		n &= (n - 1);
	}
	return count;
}

// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
	// Return count of set bits in
	// a XOR b
	return countSetBits(a ^ b);
}

// Driver code
int main()
{
	int a = 10;
	int b = 20;

	// Function call
	cout << FlippedCount(a, b) << endl;
	return 0;
}

// This code is contributed by Sania Kumari Gupta
// (kriSania804)
