/*
Has Path
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not.
Print true if the path exists and false otherwise.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1

Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
true


Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool hasPath(vector<vector<bool>>& edges, vector<bool>& visited, int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i = 0; i < edges.size(); i++) {
            if(edges[front][i] and !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
    return visited[end];
}
int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    
    vector<vector<bool>> edges(v, vector<bool>(v, false));
    
    for(int i = 0; i < e; i++) {
        int first;
        int second;
        cin >> first >> second;
        edges[first][second] = true;
        edges[second][first] = true;
    }
    
    // Take the start and end vertex as input
    int start, end;
    cin >> start >> end;
    
    vector<bool> visited(v,false);
    
    if(hasPath(edges, visited, start, end)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}

// Time Complexity : O(V^2)
// Auxillary Space : O(V)
