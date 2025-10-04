/*
3 Cycle
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. 
A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. 
Let us denote the two vertices with the symbol u and v. 

Output Format :
Print the count the number of 3-cycles in the given graph

Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1

Time Limit: 1 sec

Sample Input 1:
3 3
0 1
1 2
2 0

Sample Output 1:
1
*/

#include<iostream>
#include<vector>
using namespace std;

void countCycles(vector<vector<bool>>& graph, vector<bool>& visited, int current, int start, int length, int& count) {
    visited[current] = true;
    
    // If a path of length 2 is found
    if(length == 0) {
        visited[current] = false;
        if(graph[current][start]) {
            count++;
            return;
        } else {
            return;
        }
    }
    
    for(int i = 0; i < graph.size(); i++) {
        if(!visited[i] and graph[current][i]) {
	     countCycles(graph, visited, i, start, length - 1, count);
        }
    }
    
    visited[current] = false;
}
    

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
   	vector<vector<bool>> graph(v, vector<bool>(v, false));
    
    // corner case
    if(e == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;
        graph[first][second] = true;
        graph[second][first] = true;
    }
    
    vector<bool> visited(v, false);
    
    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            // For a 3 cycle from i we nee to find a path to vertex i of length 2
            countCycles(graph, visited, i, i, 2, count);
            visited[i] = true;
        }
    }
    
    // Since every path will be counted twice so we divide by 2
    cout << count / 2 << endl;
    return 0;
}

// Time Complexity : O(V^2)
// Auxillary Space : O(V^2)
