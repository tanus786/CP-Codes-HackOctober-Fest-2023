/*
Is Connected ?
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Time Limit: 1 second

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true


Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 

Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

bool isConnected(unordered_map<int, vector<int>>& graph, int v, int start) {
    queue<int> q;
    vector<bool> visited(v, false);
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i = 0; i < graph[front].size(); i++) {
        	int curr = graph[front][i];
            if(!visited[curr]) {
                q.push(curr);
                visited[curr] = true;
            }
        }
    }
    // If the graph is connected then the visted vector must be all true
    for(auto it : visited) {
        if(!it) {
            return false;
        }
    }

    return true;
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    // corner case
    // If no edge is present
	if(e == 0) {
        if(v == 0 or v == 1) {
            cout << "true" << endl; 
        } else {
            cout << "false" << endl;
        }
        return 0;
    }
    
    unordered_map<int, vector<int>> graph;
    int first = -1;
    int second = -1;
    
    for(int i = 0; i < e; i++) {
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
        // Instead of Adjacency matrix, using adjacency list to reduce complexity
    }
    
    if(isConnected(graph, v, first)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}

// Time Complexity : O(V + E)
// Auxillary Space : O(V)
