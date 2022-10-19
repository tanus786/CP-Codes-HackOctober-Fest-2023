// Dominos

// Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, 
// it knocks down the next one, which knocks down the one after that, all the way down the line.

// However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos
//  falling again.
// Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand
//  in order for all of the dominos to fall.

// Input Format:
// The first line of input contains one integer T, specifying the number of test cases to follow.
// Each test case begins with a line containing two integers
// The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case.
// The domino tiles are numbered from 1 to n.
// Each of the following lines contains two integers x and y indicating that if domino number x falls,
//  it will cause domino number y to fall as well.

// Constraints:
// 1 <= T <= 50
// 1 <= N, M <= 10^5

// Output Format:
// For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by
//  hand in order for all the dominos to fall.

// Sample Input 1:
// 1
// 3 2
// 1 2
// 2 3
// Sample Output 2:
// 1




#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &edges, int current, vector<bool> &visited, stack<int> &s, int flag)
{
    visited[current] = true;
    for (int i = 0; i < edges[current].size(); i++)
    {
        if (!visited[edges[current][i]])
        {
            dfs(edges, edges[current][i], visited, s, flag);
        }
    }

    if (flag)
    {
        s.push(current);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n + 1);
        while (m--)
        {
            int sv, ev;
            cin >> sv >> ev;
            edges[sv - 1].push_back(ev - 1);
        }
        vector<bool> visited(n, false);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(edges, i, visited, s, true);
        }

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int count = 0;
        while (!s.empty())
        {
            int current = s.top();
            s.pop();
            if (!visited[current])
            {
                count++;
                dfs(edges, current, visited, s, false);
            }
        }
        cout << count << endl;
    }

    return 0;
}
