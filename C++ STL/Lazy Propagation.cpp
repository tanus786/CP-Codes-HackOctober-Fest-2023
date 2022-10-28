/* A recursive function to update the nodes which have the given
index in their range. The following are parameters
	tree[] --> segment tree
	si	 --> index of current node in segment tree.
				Initial value is passed as 0.
	ss and se --> Starting and ending indexes of array elements
				covered under this node of segment tree.
				Initial values passed as 0 and n-1.
	i --> index of the element to be updated. This index
			is in input array.
diff --> Value to be added to all nodes which have array
			index i in range */
void updateValueUtil(int tree[], int ss, int se, int i,
					int diff, int si)
{
	// Base Case: If the input index lies outside the range
	// of this segment
	if (i < ss || i > se)
		return;

	// If the input index is in range of this node, then
	// update the value of the node and its children
	st[si] = st[si] + diff;
	if (se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
		updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
	}
}
