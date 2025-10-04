// Recursive Program to remove consecutive
// duplicates from string S.
#include <bits/stdc++.h>
using namespace std;

// A recursive function that removes
// consecutive duplicates from string S
void removeDuplicates(char* S)
{
	// When string is empty, return
	if (S[0] == '\0')
		return;

	// if the adjacent characters are same
	if (S[0] == S[1]) {

		// Shift character by one to left
		int i = 0;
		while (S[i] != '\0') {
			S[i] = S[i + 1];
			i++;
		}

		// Check on Updated String S
		removeDuplicates(S);
	}

	// If the adjacent characters are not same
	// Check from S+1 string address
	removeDuplicates(S + 1);
}

// Driver Program
int main()
{
	char S1[] = "geeksforgeeks";
	removeDuplicates(S1);
	cout << S1 << endl;

	char S2[] = "aabcca";
	removeDuplicates(S2);
	cout << S2 << endl;

	return 0;
}
