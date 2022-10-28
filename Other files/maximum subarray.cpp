// A simple C++ program to find max subarray XOR
#include<bits/stdc++.h>
using namespace std;

int maxSubarrayXOR(int arr[], int n)
{
	int ans = INT_MIN;	 // Initialize result

	// Pick starting points of subarrays
	for (int i=0; i<n; i++)
	{
		int curr_xor = 0; // to store xor of current subarray

		// Pick ending points of subarrays starting with i
		for (int j=i; j<n; j++)
		{
			curr_xor = curr_xor ^ arr[j];
			ans = max(ans, curr_xor);
		}
	}
	return ans;
}

// Driver program to test above functions
int main()
{
	int arr[] = {8, 1, 2, 12};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n);
	return 0;
}
