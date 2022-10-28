// HOLI - Holiday Accommodation

// Nowadays, people have many ways to save money on accommodation when they are on vacation. One of these ways is exchanging houses with other people.

// Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:

// All the people should go to one of the other people's city.
// Two of them never go to the same city, because they are not willing to share a house.
// They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.

// Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.

// Input
// The first line of input contains one integer T (1 ≤ T ≤ 10), indicating the number of test cases.

// Each test case contains several lines. The first line contains an integer N (2 ≤ N ≤ 105), representing the number of cities. Then the following N-1 lines each contains three integers X, Y, Z (1 ≤ X, Y ≤ N, 1 ≤ Z ≤ 106), means that there is a highway between city X and city Y, and length of that highway.

// You can assume all the cities are connected and the highways are bi-directional.

// Output
// For each test case in the input, print one line: "Case #X: Y", where X is the test case number (starting with 1) and Y represents the largest total travel distance of all people.

// Example
// Input:
// 2
// 4
// 1 2 3
// 2 3 2
// 4 3 2
// 6
// 1 2 3
// 2 3 4
// 2 4 1
// 4 5 8
// 5 6 5

// Output:
// Case #1: 18
// Case #2: 62

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt));
    }
    int dfs_helper(int node, bool *visited, int *count, long long &ans)
    {
        visited[node] = true;
        count[node] = 1;

        for (auto nbr_pair : l[node])
        {
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if (!visited[nbr])
            {
                count[node] += dfs_helper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = V - nx;
                ans += 2 * min(nx, ny) * wt;
            }
        }
        return count[node];
    }
    long long dfs()
    {
        bool *visited = new bool[V]{false};
        int *count = new int[V]{0};
        long long ans = 0;
        dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        Graph g(n);
        for (int j = 0; j < n - 1; j++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g.addEdge(x - 1, y - 1, z);
        }
        cout << "Case #" << i << ": " << g.dfs() << endl;
    }
    return 0;
}