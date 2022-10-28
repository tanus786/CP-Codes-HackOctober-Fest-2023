// C++ program to implement all the
// above functionalities

#include <bits/stdc++.h>
using namespace std;

// Function to get the bit at the
// ith position
bool getBit(int num, int i)
{
	// Return true if the ith bit is
	// set. Otherwise return false
	return ((num & (1 << i)) != 0);
}

// Function to set the ith bit of the
// given number num
int setBit(int num, int i)
{
	// Sets the ith bit and return
	// the updated value
	return num | (1 << i);
}

// Function to clear the ith bit of
// the given number N
int clearBit(int num, int i)
{

	// Create the mask for the ith
	// bit unset
	int mask = ~(1 << i);

	// Return the update value
	return num & mask;
}

// Driver Code
int main()
{
	// Given number N
	int N = 70;

	cout << "The bit at the 3rd position from LSB is: "
		<< (getBit(N, 3) ? '1' : '0')
		<< endl;

	cout << "The value of the given number "
		<< "after setting the bit at "
		<< "LSB is: "
		<< setBit(N, 0) << endl;

	cout << "The value of the given number "
		<< "after clearing the bit at "
		<< "LSB is: "
		<< clearBit(N, 0) << endl;

	return 0;
}
