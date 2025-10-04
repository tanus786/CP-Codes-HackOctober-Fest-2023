/*
Largest Piece
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's 
share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000

Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1

Sample Output 1:
3
*/

#include<vector>

int dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    
    visited[start] = true;
    int ans = 0;
    for(auto currentChild : graph[start]) {
        if(!visited[currentChild]) {
            int temp = dfs(graph, visited, currentChild);
            ans += temp;
        }
    }
    
    return ans  + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    vector<vector<int>> value(n, vector<int>(n, -1)); // To identify matrix entry with graph node
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            value[i][j] = count++;  // Each cell of the matrix is uniquely identified as a graph node with an integer value
        }
    }
    
    vector<vector<int>> graph(count);
    
    // We create adjacency matrix 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if(cake[i][j] == 1) {
                if(j - 1 >= 0 and cake[i][j] == cake[i][j - 1]) {
                     graph[value[i][j]].push_back(value[i][j - 1]);
                }
            
                if(j + 1 < n and cake[i][j] == cake[i][j + 1]) {
                    graph[value[i][j]].push_back(value[i][j + 1]);
                }
            
                if(i - 1 >= 0 and cake[i][j] == cake[i - 1][j]) {
                    graph[value[i][j]].push_back(value[i - 1][j]);
                }
            
                if(i + 1 < n and cake[i][j] == cake[i + 1][j]) {
                    graph[value[i][j]].push_back(value[i + 1][j]);
                }
            }
        }
    }
    
    vector<bool> visited(count, false);
    
    int ans = 0;
    for(int i = 0; i < count ; i++) {
        // if a matrix cell has 0 value then we skip the dfs call for that
        if(i < n) {
            if(cake[0][i] == 0) {
                continue;
            }
        } else {
            if(cake[i / n][i - (i / n) * n] == 0) {
                continue;
            }
        }
        
        if(!visited[i]) {
            int temp = dfs(graph, visited, i);
            ans = max(ans, temp);
        }
    }
    
    return ans;
} 

// Time Complexity : O(n * n)
// Auxillary Space : O(n * n)
