// C++ program to demonstrate Range Update
// and Point Queries Without using BIT
#include <bits/stdc++.h>
using namespace std;

// Updates such that getElement() gets an increased
// value when queried from l to r.
void update(int arr[], int l, int r, int val)
{
	arr[l] += val;
	arr[r+1] -= val;
}

// Get the element indexed at i
int getElement(int arr[], int i)
{
	// To get ith element sum of all the elements
	// from 0 to i need to be computed
	int res = 0;
	for (int j = 0 ; j <= i; j++)
		res += arr[j];

	return res;
}

// Driver program to test above function
int main()
{
	int arr[] = {0, 0, 0, 0, 0};
	int n = sizeof(arr) / sizeof(arr[0]);

	int l = 2, r = 4, val = 2;
	update(arr, l, r, val);

	//Find the element at Index 4
	int index = 4;
	cout << "Element at index " << index << " is " <<
		getElement(arr, index) << endl;

	l = 0, r = 3, val = 4;
	update(arr,l,r,val);

	//Find the element at Index 3
	index = 3;
	cout << "Element at index " << index << " is " <<
		getElement(arr, index) << endl;

	return 0;
}
