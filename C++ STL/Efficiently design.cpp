// A C++ program to implement insert, delete and
// median queries using segment tree
#include<bits/stdc++.h>
#define maxn 3000005
#define max_elem 1000000
using namespace std;

// A global array to store segment tree.
// Note: Since it is global, all elements are 0.
int segmentTree[maxn];

// Update 'node' and its children in segment tree.
// Here 'node' is index in segmentTree[], 'a' and
// 'b' are starting and ending indexes of range stored
// in current node.
// 'diff' is the value to be added to value 'x'.
void update(int node, int a, int b, int x, int diff)
{
	// If current node is a leaf node
	if (a == b && a == x )
	{
		// add 'diff' and return
		segmentTree[node] += diff;
		return ;
	}

	// If current node is non-leaf and 'x' is in its
	// range
	if (x >= a && x <= b)
	{
		// update both sub-trees, left and right
		update(node*2, a, (a + b)/2, x, diff);
		update(node*2 + 1, (a + b)/2 + 1, b, x, diff);

		// Finally update current node
		segmentTree[node] = segmentTree[node*2] +
							segmentTree[node*2 + 1];
	}
}

// Returns k'th node in segment tree
int findKth(int node, int a, int b, int k)
{
	// non-leaf node, will definitely have both
	// children; left and right
	if (a != b)
	{
		// If kth element lies in the left subtree
		if (segmentTree[node*2] >= k)
			return findKth(node*2, a, (a + b)/2, k);

		// If kth one lies in the right subtree
		return findKth(node*2 + 1, (a + b)/2 + 1,
					b, k - segmentTree[node*2]);
	}

	// if at a leaf node, return the index it stores
	// information about
	return (segmentTree[node])? a : -1;
}

// insert x in the set
void insert(int x)
{
	update(1, 0, max_elem, x, 1);
}

// delete x from the set
void delete(int x)
{
	update(1, 0, max_elem, x, -1);
}

// returns median element of the set with odd
// cardinality only
int median()
{
	int k = (segmentTree[1] + 1) / 2;
	return findKth(1, 0, max_elem, k);
}

// Driver code
int main()
{
	insert(1);
	insert(4);
	insert(7);
	cout << "Median for the set {1,4,7} = "
		<< median() << endl;
	insert(8);
	insert(9);
	cout << "Median for the set {1,4,7,8,9} = "
		<< median() << endl;
	delete(1);
	delete(8);
	cout << "Median for the set {4,7,9} = "
		<< median() << endl;
	return 0;
}
