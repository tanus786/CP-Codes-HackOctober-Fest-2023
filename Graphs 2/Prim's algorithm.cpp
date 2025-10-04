/*
Prim's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.

For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first 
while printing an edge.

2. Print V-1 edges in above format in different lines.

Note : Order of different edges doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
Print the MST, as described in the task.

Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5

Time Limit: 1 sec

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int getMinimumVertex(vector<bool>& visited, vector<int>& weight) {
    int v = visited.size();
    int minVertex = -1;
    for(int i = 0; i < v; i++) {
        if(!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex])) {
        	minVertex = i;
        }
    }
    
    return minVertex;
}


vector<pair<pair<int,int>,int>> primsMST(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent, vector<int>& weight) {
    // First we find the vertex with minimum weight and then explore the remaining vertex
    int v = visited.size();
    // The loop runs to v - 1 since when we reach the last vertex
    // al of it's neightbour would already have been analysed
    for(int i = 0; i < v - 1; i++) {
        // minimum weighted vertex
        int minVertex = getMinimumVertex(visited, weight);
        visited[minVertex] = true;
        
        // Exploring the neighbours of minVertex
        for(int j = 0; j < v; j++) {
            if(graph[minVertex][j] and !visited[j] and graph[minVertex][j] < weight[j]) {
                weight[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }
    
    vector<pair<pair<int,int>,int>> answer;
    
    // Here the loop starts with 1 since parent[0] = -1 and as such there is no edge that ends at zero.
    for(int i = 1; i < v; i++) {
        if(parent[i] < i) {
            answer.push_back({{parent[i], i}, weight[i]});
        } else {
            answer.push_back({{i, parent[i]}, weight[i]});
        }
    }
    
    return answer;
} 
    


int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> graph(v, vector<int>(v));
    
    for(int i = 0; i < e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source][destination] = weight;
        graph[destination][source] = weight;
    }
    
    vector<bool> visited(v, false);
    
    vector<int> parent(v);
    vector<int> weight(v, INT_MAX); // Weight of vertices initialized with infinity
    
    // Taking the 0 vertex as source
    parent[0] = -1;
    weight[0] = 0;
    
    vector<pair<pair<int,int>,int>> MST = primsMST(graph, visited, parent, weight);
    
	for(auto it : MST) {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
    
    return 0;
}

// Time Complexity : O(V^2) 
// Auxillary Space : O(V^2)
// Note : We can use priority queue and adjacency list to reduce the complexity to O((E + v)logV)
