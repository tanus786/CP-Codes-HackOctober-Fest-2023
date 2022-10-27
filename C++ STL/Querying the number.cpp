// A C++ program implementing the above design
#include<bits/stdc++.h>
#define max_color 1000005
#define maxn 100005
using namespace std;

// Note: All elements of global arrays are
// initially zero
// All the arrays have been described above
int bit[maxn], vis_time[maxn], end_time[maxn];
int flat_tree[2 * maxn];
vector<int> tree[maxn];
vector<int> table[max_color];
int traverser[max_color];

bool vis[maxn];
int tim = 0;

//li, ri and index are stored in queries vector
//in that order, as the sort function will use
//the value li for comparison
vector< pair< pair<int, int>, int> > queries;

//ans[i] stores answer to ith query
int ans[maxn];

//update function to add val to idx in BIT
void update(int idx, int val)
{
	while ( idx < maxn )
	{
		bit[idx] += val;
		idx += idx & -idx;
	}
}

//query function to find sum(1, idx) in BIT
int query(int idx)
{
	int res = 0;
	while ( idx > 0 )
	{
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}

void dfs(int v, int color[])
{
	//mark the node visited
	vis[v] = 1;

	//set visiting time of the node v
	vis_time[v] = ++tim;

	//use the color of node v to fill flat_tree[]
	flat_tree[tim] = color[v];

	vector<int>::iterator it;
	for (it=tree[v].begin(); it!=tree[v].end(); it++)
		if (!vis[*it])
			dfs(*it, color);


	// set ending time for node v
	end_time[v] = ++tim;

	// setting its color in flat_tree[] again
	flat_tree[tim] = color[v];
}

//function to add an edge(u, v) to the tree
void addEdge(int u, int v)
{
	tree[u].push_back(v);
	tree[v].push_back(u);
}

//function to build the table[] and also add
//first occurrences of elements to the BIT
void hashMarkFirstOccurrences(int n)
{
	for (int i = 1 ; i <= 2 * n ; i++)
	{
		table[flat_tree[i]].push_back(i);

		//if it is the first occurrence of the element
		//then add it to the BIT and increment traverser
		if (table[flat_tree[i]].size() == 1)
		{
			//add the occurrence to bit
			update(i, 1);

			//make traverser point to next occurrence
			traverser[flat_tree[i]]++;
		}
	}
}

//function to process all the queries and store their answers
void processQueries()
{
	int j = 1;
	for (int i=0; i<queries.size(); i++)
	{
		//for each query remove all the occurrences before its li
		//li is the visiting time of the node
		//which is stored in first element of first pair
		for ( ; j < queries[i].first.first ; j++ )
		{
			int elem = flat_tree[j];

			//update(i, -1) removes an element at ith index
			//in the BIT
			update( table[elem][traverser[elem] - 1], -1);

			//if there is another occurrence of the same element
			if ( traverser[elem] < table[elem].size() )
			{
				//add the occurrence to the BIT and
				//increment traverser
				update(table[elem][ traverser[elem] ], 1);
				traverser[elem]++;
			}
		}

		//store the answer for the query, the index of the query
		//is the second element of the pair
		//And ri is stored in second element of the first pair
		ans[queries[i].second] = query(queries[i].first.second);
	}
}

// Count distinct colors in subtrees rooted with qVer[0],
// qVer[1], ...qVer[qn-1]
void countDistinctColors(int color[], int n, int qVer[], int qn)
{
	// build the flat_tree[], vis_time[] and end_time[]
	dfs(1, color);

	// add query for u = 3, 2 and 7
	for (int i=0; i<qn; i++)
		queries.push_back(make_pair(make_pair(vis_time[qVer[i]],
									end_time[qVer[i]]), i) );

	// sort the queries in order of increasing vis_time
	sort(queries.begin(), queries.end());

	// make table[] and set '1' at first occurrences of elements
	hashMarkFirstOccurrences(n);

	// process queries
	processQueries();

	// print all the answers, in order asked
	// in the question
	for (int i=0; i<queries.size() ; i++)
	{
		cout << "Distinct colors in the corresponding subtree"
		"is: " << ans[i] << endl;
	}
}

//driver code
int main()
{
	/*
			1
		/ \
		2 3
		/|\ | \
		4 5 6 7 8
			/| \
			9 10 11 */
	int n = 11;
	int color[] = {0, 2, 3, 3, 4, 1, 3, 4, 3, 2, 1, 1};

	// add all the edges to the tree
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(2, 4);
	addEdge(2, 5);
	addEdge(2, 6);
	addEdge(3, 7);
	addEdge(3, 8);
	addEdge(7, 9);
	addEdge(7, 10);
	addEdge(7, 11);


	int qVer[] = {3, 2, 7};
	int qn = sizeof(qVer)/sizeof(qVer[0]);

	countDistinctColors(color, n, qVer, qn);

	return 0;
}
