// C++ program to find minimum number of flip to make binary
// string alternate
#include <bits/stdc++.h>
using namespace std;

// Utility method to flip a character
char flip(char ch) { return (ch == '0') ? '1' : '0'; }

// Utility method to get minimum flips when alternate
// string starts with expected char
int getFlipWithStartingCharcter(string str, char expected)
{
	int flipCount = 0;
	for (int i = 0; i < str.length(); i++) {
		// if current character is not expected, increase
		// flip count
		if (str[i] != expected)
			flipCount++;

		// flip expected character each time
		expected = flip(expected);
	}
	return flipCount;
}

// method return minimum flip to make binary string
// alternate
int minFlipToMakeStringAlternate(string str)
{
	// return minimum of following two
	// 1) flips when alternate string starts with 0
	// 2) flips when alternate string starts with 1
	return min(getFlipWithStartingCharcter(str, '0'),
			getFlipWithStartingCharcter(str, '1'));
}

// Driver code to test above method
int main()
{
	string str = "0001010111";
	cout << minFlipToMakeStringAlternate(str);
	return 0;
}

// This code is contributed by Sania Kumari Gupta
// (kriSania804)
