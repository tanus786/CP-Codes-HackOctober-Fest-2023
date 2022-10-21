// C++ program to implement Shanks Tonelli algorithm for
// finding Modular Square Roots
#include <bits/stdc++.h>
using namespace std;

// utility function to find pow(base, exponent) % modulus
int pow(int base, int exponent, int modulus)
{
	int result = 1;
	base = base % modulus;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		result = (result * base)% modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

// utility function to find gcd
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

// Returns k such that b^k = 1 (mod p)
int order(int p, int b)
{
	if (gcd(p, b) != 1)
	{
		printf("p and b are not co-prime.\n");
		return -1;
	}

	// Initializing k with first odd prime number
	int k = 3;
	while (1)
	{
		if (pow(b, k, p) == 1)
			return k;
		k++;
	}
}

// function return p - 1 (= x argument) as x * 2^e,
// where x will be odd sending e as reference because
// updation is needed in actual e
int convertx2e(int x, int& e)
{
	e = 0;
	while (x % 2 == 0)
	{
		x /= 2;
		e++;
	}
	return x;
}

// Main function for finding the modular square root
int STonelli(int n, int p)
{
	// a and p should be coprime for finding the modular
	// square root
	if (gcd(n, p) != 1)
	{
		printf("a and p are not coprime\n");
		return -1;
	}

	// If below expression return (p - 1) then modular
	// square root is not possible
	if (pow(n, (p - 1) / 2, p) == (p - 1))
	{
		printf("no sqrt possible\n");
		return -1;
	}

	// expressing p - 1, in terms of s * 2^e, where s
	// is odd number
	int s, e;
	s = convertx2e(p - 1, e);

	// finding smallest q such that q ^ ((p - 1) / 2)
	// (mod p) = p - 1
	int q;
	for (q = 2; ; q++)
	{
		// q - 1 is in place of (-1 % p)
		if (pow(q, (p - 1) / 2, p) == (p - 1))
			break;
	}

	// Initializing variable x, b and g
	int x = pow(n, (s + 1) / 2, p);
	int b = pow(n, s, p);
	int g = pow(q, s, p);

	int r = e;

	// keep looping until b become 1 or m becomes 0
	while (1)
	{
		int m;
		for (m = 0; m < r; m++)
		{
			if (order(p, b) == -1)
				return -1;

			// finding m such that b^ (2^m) = 1
			if (order(p, b) == pow(2, m))
				break;
		}
		if (m == 0)
			return x;

		// updating value of x, g and b according to
		// algorithm
		x = (x * pow(g, pow(2, r - m - 1), p)) % p;
		g = pow(g, pow(2, r - m), p);
		b = (b * g) % p;

		if (b == 1)
			return x;
		r = m;
	}
}

// driver program to test above function
int main()
{
	int n = 2;

	// p should be prime
	int p = 113;

	int x = STonelli(n, p);

	if (x == -1)
		printf("Modular square root is not exist\n");
	else
		printf("Modular square root of %d and %d is %d\n",
				n, p, x);
}
