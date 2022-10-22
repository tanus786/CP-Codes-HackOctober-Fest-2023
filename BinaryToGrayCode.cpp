// CPP program to convert Binary to
// Gray code using recursion
#include <bits/stdc++.h>
using namespace std;

// Function to change Binary to
// Gray using recursion
int binary_to_gray(int n)
{
	if (!n)
		return 0;

	// Taking last digit
	int a = n % 10;

	// Taking second last digit
	int b = (n / 10) % 10;

	// If last digit are opposite bits
	if ((a && !b) || (!a && b))
		return (1 + 10 * binary_to_gray(n / 10));

	// If last two bits are same
	return (10 * binary_to_gray(n / 10));
}

// Driver Function
int main()
{
	int binary_number = 1011101;

	printf("%d", binary_to_gray(binary_number));
	return 0;
}
