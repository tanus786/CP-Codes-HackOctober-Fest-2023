/*
All connected components
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components 
doesn't matter.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different 
components doesn't matter.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Sample Input 1:
4 2
0 1
2 3

Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
0 1 3 
2
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> helper(unordered_map<int, vector<int>>& graph , vector<bool>& visited, int start) {
    vector<int> current_component;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int front = q.front();
        current_component.push_back(front);
        q.pop();
        
        for(int i = 0; i < graph[front].size(); i++) {
            int current = graph[front][i];
            if(!visited[current]) {
                visited[current] = true;
                q.push(current);
            }
        }
    }
    
    sort(current_component.begin(), current_component.end());
    return current_component;
}

int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    
    unordered_map<int, vector<int>> graph;
    
    for(int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    
    vector<bool> visited(v, false);
    
    vector<vector<int>> connected_component;
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            connected_component.push_back(helper(graph, visited, i));
        }
    }
    
    for(auto it : connected_component) {
        for(auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }
}

// Time Complexity : O(VlogV)
// Auxillary Space : O(V)
