/*
Kruskal's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

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

Time Limit: 1 sec

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
    public:
    	int source;
    	int destination;
    	int weight; 
    	
    	Edge(int source, int destination, int weight) {
            this -> source = source;
            this -> destination = destination;
            this -> weight  = weight;
        } 
};


bool sortByWeight(Edge const &a, Edge const &b) {
    return a.weight < b.weight;
}

// Union Find
int getParent(vector<int>& parent, int vertex) {
    // base case
    if(parent[vertex] == vertex) {
        return vertex;
    }
    
    return getParent(parent, parent[vertex]);
    
}

vector<Edge> kruskalMST(vector<Edge>& graph, vector<int> &parent) {
    int v = parent.size();
    
    int count = 0;
    int index = 0;
    
    vector<Edge> answer;
    
    while(count != v - 1) {
        Edge currentEdge = graph[index];
        
        // Using Unio Find algorithm -> O(EV) Time
        int parentOfSource = getParent(parent, currentEdge.source);
        int parentOfDestination = getParent(parent, currentEdge.destination);
        
        if(parentOfSource != parentOfDestination) {
            answer.push_back(currentEdge);
            count++;
            parent[parentOfDestination] = parentOfSource;
        }
        
        index++;
    }
    
    return answer;
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    vector<Edge> graph;
    
    for(int i = 0; i < e; i++) {
		int source;
        int destination;
        int weight;
        cin >> source >> destination >> weight;
        
        Edge edge(source, destination, weight);
        graph.push_back(edge);
    }
    
    sort(graph.begin(), graph.end(), sortByWeight);
    
    vector<int> parent(v);
    
	for(int i = 0; i < v; i++) {
        parent[i] = i;
    }
    
    vector<Edge> MST = kruskalMST(graph, parent);
    
    for(auto it : MST) {
        if(it.source < it.destination) {
        	cout << it.source << " " << it.destination << " " << it.weight;
        } else {
            cout << it.destination << " " << it.source << " " << it.weight;
        }
        cout << endl;
    }
}

// Time Complexity : O(ElogE + EV)
// Auxilalry Space : O(V + E)
