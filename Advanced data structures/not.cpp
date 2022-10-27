// A C++ implementation of the above idea
#include<bits/stdc++.h>
#define maxy 1000005
#define maxn 10005

using namespace std;

// structure to store point
struct point
{
	int x, y;
	point(int a, int b)
	{
		x = a, y = b;
	}
};

// Note: Global arrays are initially zero
// array to store BIT and vector to store
// the points and their corresponding event number,
// in the second field of the pair
int bit[maxy];
vector<pair<point, int> > events;

// compare function to sort in order of non-decreasing
// x coordinate and if x coordinates are same then
// order on the basis of events on the points
bool cmp(pair<point, int> &a, pair<point, int> &b)
{
	if ( a.first.x != b.first.x )
		return a.first.x < b.first.x;

	//if the x coordinates are same
	else
	{
		// both points are of the same vertical line
		if (a.second == 3 && b.second == 3)
		{
			return true;
		}

		// if an 'in' event occurs before 'vertical'
		// line event for the same x coordinate
		else if (a.second == 1 && b.second == 3)
		{
			return true;
		}

		// if a 'vertical' line comes before an 'in'
		// event for the same x coordinate, swap them
		else if (a.second == 3 && b.second == 1)
		{
			return false;
		}

		// if an 'out' event occurs before a 'vertical'
		// line event for the same x coordinate, swap.
		else if (a.second == 2 && b.second == 3)
		{
			return false;
		}

		//in all other situations
		return true;
	}
}

// update(y, 1) inserts a horizontal line at y coordinate
// in an active region, while update(y, -1) removes it
void update(int idx, int val)
{
	while (idx < maxn)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}

// returns the number of lines in active region whose y
// coordinate is between 1 and idx
int query(int idx)
{
	int res = 0;
	while (idx > 0)
	{
		res += bit[idx];
		idx -= idx & (-idx);
	}
	return res;
}

// inserts a line segment
void insertLine(point a, point b)
{
	// if it is a horizontal line
	if (a.y == b.y)
	{
		int beg = min(a.x, b.x);
		int end = max(a.x, b.x);

		// the second field in the pair is the event number
		events.push_back(make_pair(point(beg, a.y), 1));
		events.push_back(make_pair(point(end, a.y), 2));
	}

	//if it is a vertical line
	else
	{
		int up = max(b.y, a.y);
		int low = min(b.y, a.y);

		//the second field of the pair is the event number
		events.push_back(make_pair(point(a.x, up), 3));
		events.push_back(make_pair(point(a.x, low), 3));
	}
}

// returns the number of intersection points between all
// the lines, vertical and horizontal, to be run after the
// points have been sorted using the cmp() function
int findIntersectionPoints()
{
	int intersection_pts = 0;
	for (int i = 0 ; i < events.size() ; i++)
	{
		//if the current point is on an 'in' event
		if (events[i].second == 1)
		{
			//insert the 'y' coordinate in the active region
			update(events[i].first.y, 1);
		}

		// if current point is on an 'out' event
		else if (events[i].second == 2)
		{
			// remove the 'y' coordinate from the active region
			update(events[i].first.y, -1);
		}

		// if the current point is on a 'vertical' line
		else
		{
			// find the range to be queried
			int low = events[i++].first.y;
			int up = events[i].first.y;
			intersection_pts += query(up) - query(low);
		}
	}
	return intersection_pts;
}

// returns (intersection_pts)C3
int findNumberOfTriangles()
{
	int pts = findIntersectionPoints();
	if ( pts >= 3 )
		return ( pts * (pts - 1) * (pts - 2) ) / 6;
	else
		return 0;
}


// driver code
int main()
{
	insertLine(point(2, 1), point(2, 9));
	insertLine(point(1, 7), point(6, 7));
	insertLine(point(5, 2), point(5, 8));
	insertLine(point(3, 4), point(6, 4));
	insertLine(point(4, 3), point(4, 5));
	insertLine(point(7, 6), point(9, 6));
	insertLine(point(8, 2), point(8, 5));

	// sort the points based on x coordinate
	// and event they are on
	sort(events.begin(), events.end(), cmp);

	cout << "Number of triangles are: " <<
		findNumberOfTriangles() << "\n";

	return 0;
}
