#include <iostream>
using namespace std;

void constructLowerArray(int arr[], int *countSmaller,
						int n)
{
	int i, j;
	
	// Initialize all the counts in
	// countSmaller array as 0
	for(i = 0; i < n; i++)
		countSmaller[i] = 0;
	
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
				countSmaller[i]++;
		}
	}
}

// Utility function that prints
// out an array on a line
void printArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		cout << arr[i] << " ";
		
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 10, 5, 4, 2,
				20, 6, 1, 0, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int *low = (int *)malloc(sizeof(int)*n);
	
	constructLowerArray(arr, low, n);
	printArray(low, n);
	
	return 0;
}

// This code is contributed by Hemant Jain
