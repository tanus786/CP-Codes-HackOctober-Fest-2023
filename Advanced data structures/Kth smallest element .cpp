// kth largest element in a 2d array sorted row-wise and
// column-wise
#include <bits/stdc++.h>
using namespace std;

// A structure to store entry of heap. The entry contains
// value from 2D array, row and column numbers of the value
struct HeapNode {
	int val; // value to be stored
	int r; // Row number of value in 2D array
	int c; // Column number of value in 2D array
};

// A utility function to minheapify the node harr[i] of a
// heap stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if(l < heap_size&& r<heap_size && harr[l].val < harr[i].val && harr[r].val < harr[i].val){
			HeapNode temp=harr[r];
			harr[r]=harr[i];
			harr[i]=harr[l];
			harr[l]=temp;
			minHeapify(harr ,l,heap_size);
			minHeapify(harr ,r,heap_size);
		}
		if (l < heap_size && harr[l].val < harr[i].val){
			HeapNode temp=harr[i];		
			harr[i]=harr[l];
			harr[l]=temp;
			minHeapify(harr ,l,heap_size);
		}
}

// This function returns kth
// smallest element in a 2D array
// mat[][]
int kthSmallest(int mat[4][4], int n, int k)
{
	// k must be greater than 0 and smaller than n*n
	if (k < 0 || k >= n * n)
		return INT_MAX;

	// Create a min heap of elements from first row of 2D
	// array
	HeapNode harr[n];
	for (int i = 0; i < n; i++)
		harr[i] = { mat[0][i], 0, i };

	HeapNode hr;
	for (int i = 0; i < k; i++) {
		// Get current heap root
		hr = harr[0];

		// Get next value from column of root's value. If
		// the value stored at root was last value in its
		// column, then assign INFINITE as next value
		int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c]: INT_MAX;

		// Update heap root with next value
		harr[0] = { nextval, (hr.r) + 1, hr.c };

		// Heapify root
		minHeapify(harr, 0, n);
	}

	// Return the value at last extracted root
	return hr.val;
}

// driver program to test above function
int main()
{
	int mat[4][4] = {
		{ 10, 20, 30, 40 },
		{ 15, 25, 35, 45 },
		{ 25, 29, 37, 48 },
		{ 32, 33, 39, 50 },
	};
	cout << "7th smallest element is "
		<< kthSmallest(mat, 4, 7);
	return 0;
}

// this code is contributed by Rishabh Chauhan
