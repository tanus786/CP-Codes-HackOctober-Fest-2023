/*
Dijkstra's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be 
separated by a single space.

Note : Order of vertices in output doesn't matter.

Constraints :
2 <= V, E <= 10^5

Time Limit: 1 sec

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int getMinimumVertex(vector<bool>& visited, vector<int>& distance) {
    int v = visited.size();
    
    int minVertex = -1;
    for(int i = 0; i < v; i++) {
        if(!visited[i] and (minVertex == -1 or distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    
    return minVertex;
}

vector<pair<int,int>> dijkstraShortestPath(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& distance) {
	int v = visited.size();
    int currentDistance = 0;
    for(int i = 0; i < v - 1; i++) {
        int minVertex = getMinimumVertex(visited, distance);
        visited[minVertex] = true;
        // Explore its neighbour
        for(int j = 0; j < v; j++) {
            if(graph[minVertex][j] and !visited[j] and graph[minVertex][j] + distance[minVertex] < distance[j]) {
                distance[j] = graph[minVertex][j] + distance[minVertex];
            }
        }
    }
    
    vector<pair<int,int>> answer;
        
    for(int i = 0; i < v; i++) {
        answer.push_back({i, distance[i]});
    }
        
	return answer; 
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> graph(v, vector<int>(v));
	
    for(int i = 0; i < e; i++) {
        int source, destination, cost;
        cin >> source >> destination >> cost;
        graph[source][destination] = cost;
        graph[destination][source] = cost;
    }
    
    vector<bool> visited(v, false);
    
    vector<int> distance(v, INT_MAX);
    
    distance[0] = 0;
    
    vector<pair<int,int>> shortestPath = dijkstraShortestPath(graph, visited, distance);
    
    for(auto it : shortestPath) {
        cout << it.first << " " << it.second << endl;
    }
     
}
// Time Complexity : O(V^2) 
// Auxillary Space : O(V^2)
// Note : Here again we can use priority queue and adjacency list to reduce the complexity to O((E + v)logV)
