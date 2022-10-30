/*
Islands
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to 
any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. 
Can you count the number of connected groups of islands.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 

Output Format :
Print the count the number of connected groups of islands

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Time Limit: 1 second

Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3

Sample Output 1:
1 
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#define line '\n'
using namespace std;

void BFS(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < graph[front].size(); i++) {
            int current = graph[front][i];
            if(!visited[current]) {
                q.push(current);
                visited[current] = true;
            }
        }
    }
}

int countComponents(unordered_map<int, vector<int>>& graph, int v) {
    vector<bool> visited(v, false);
    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            count++;
            BFS(graph, visited, i);
        }
    } 
    
    return count;
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    unordered_map<int, vector<int>> graph;
    
    
    for(int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    
    cout << countComponents(graph, v) << line;
}

// Time Complexity : O(V + E)
// Auxillary Space : O(V)
