// A Divide and Conquer Program to find maximum rectangular area in a histogram

import java.util.*;

class HIS{
static int[] hist;
static int[] st;
	

static int max(int x, int y, int z)
{ return Math.max(Math.max(x, y), z); }

static int minVal(int i, int j)
{
	if (i == -1) return j;
	if (j == -1) return i;
	return (hist[i] < hist[j])? i : j;
}
static int getMid(int s, int e)
{ return s + (e -s)/2; }

static int RMQUtil( int ss, int se, int qs, int qe, int index)
{

	if (qs <= ss && qe >= se)
	return st[index];

	
	if (se < qs || ss > qe)
	return -1;


	int mid = getMid(ss, se);
	return minVal( RMQUtil(ss, mid, qs, qe, 2*index+1),
				RMQUtil( mid+1, se, qs, qe, 2*index+2));
}


static int RMQ( int n, int qs, int qe)
{
	if (qs < 0 || qe > n-1 || qs > qe)
	{
	System.out.print("Invalid Input");
	return -1;
	}

	return RMQUtil( 0, n-1, qs, qe, 0);
}


static int constructSTUtil(int ss, int se, int si)
{
	if (ss == se)
	return (st[si] = ss);

	int mid = getMid(ss, se);
	st[si] = minVal( constructSTUtil( ss, mid, si*2+1),
					constructSTUtil( mid+1, se, si*2+2));
	return st[si];
}

static void constructST(int n)
{
	int x = (int)(Math.ceil(Math.log(n))); //Height of segment tree
	int max_size = 2*(int)Math.pow(2, x) - 1; //Maximum size of segment tree
	st = new int[max_size*2];


	constructSTUtil( 0, n-1, 0);

}

static int getMaxAreaRec( int n, int l, int r)
{

	if (l > r) return Integer.MIN_VALUE;
	if (l == r) return hist[l];


	int m = RMQ( n, l, r);

	
	return max(getMaxAreaRec( n, l, m - 1),
			getMaxAreaRec( n, m + 1, r),
			(r - l + 1)*(hist[m]) );
}


static int getMaxArea( int n)
{

	constructST(n);

	
	return getMaxAreaRec( n, 0, n - 1);
}


public static void main(String[] args)
{
	int[] a = {6, 1, 5, 4, 5, 2, 6};
	int n = a.length;
	hist = new int[n];

	hist = a;
	System.out.print("Maximum area is " + getMaxArea(n));
}
}


