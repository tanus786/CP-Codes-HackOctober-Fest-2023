// C++ program to rearrange array in alternating
// C++ program to copy set bits in a given
// range [l, r] from y to x.
#include <bits/stdc++.h>
using namespace std;

// Copy set bits in range [l, r] from y to x.
// Note that x is passed by reference and modified
// by this function.
void copySetBits(unsigned &x, unsigned y,
				unsigned l, unsigned r)
{
// l and r must be between 1 to 32
// (assuming ints are stored using
// 32 bits)
if (l < 1 || r > 32)
	return ;

// Traverse in given range
for (int i=l; i<=r; i++)
{
	// Find a mask (A number whose
	// only set bit is at i'th position)
	int mask = 1 << (i-1);

	// If i'th bit is set in y, set i'th
	// bit in x also.
	if (y & mask)
		x = x | mask;
}
}

// Driver code
int main()
{
unsigned x = 10, y = 13, l = 1, r = 32;
copySetBits(x, y, l, r);
cout << "Modified x is " << x;
return 0;
}
