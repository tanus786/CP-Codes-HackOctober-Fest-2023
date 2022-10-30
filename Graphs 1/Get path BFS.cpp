/*
Get Path - DFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). 
Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the path from v1 to v2 in reverse order.

Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1

Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
3 0 1
*/

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> getPathBFS(vector<vector<bool>>& edges, vector<bool>& visited, int start, int end) {
    if(start == end) {
        return {start};
    }
    queue<int> q;
    vector<int> parent(edges.size());
    q.push(start);
    visited[start] = true;
	
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < edges.size(); i++) {
            if(edges[front][i] and !visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    
    // Now if the end node is found in BFS Traversal it will have been visited
    if(visited[end]) {
        vector<int> path;
        path.push_back(end);
        int temp = end;
        while(parent[temp] != start) {
            path.push_back(parent[temp]);
            temp = parent[temp];
        }
        path.push_back(start);
        return path;
    } else {
        return {};
    }
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
	
    vector<vector<bool>> edges(v, vector<bool>(v, false));
    
    for(int  i = 0; i < e; i++) {
        int first;
        int second;
        cin >> first >> second;
        edges[first][second] = true;
        edges[second][first] = true;
    }

    int start, end;
    cin >> start >> end;
    
    vector<bool> visited(v, false);
    vector<int> path = getPathBFS(edges, visited, start, end);
    
	for(auto it : path) {
        cout << it << " "; 
    }
	
    return 0;
}

// Time Complexity : O(V^2)
// Auxillary Space : O(V)
