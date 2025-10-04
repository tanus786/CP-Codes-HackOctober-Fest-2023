/*
Connecting Dots
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). 
Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. 

Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.

Output Format :
Print true if there is a cycle in the board, else print false.

Constraints :
2 <= N <= 1000
2 <= M <= 1000

Time Limit: 1 second

Sample Input 1:
3 4
AAAA
ABCA
AAAA

Sample Output 1:
true
*/

#include<vector>
#include<unordered_map>

// We use dfs for cycle detection
bool dfs(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int start, int length = 1, int parent = -1) {
    visited[start] = true;
    bool flag = false;
    for(auto currentChild : graph[start]) {
        if(!visited[currentChild]) {
            flag = dfs(graph, visited, currentChild, length + 1, start);
            if(flag) {
                break;
            }
        } else {
            // If the childNode called is not the same as parent and length > 3 then we have our answer 
            if(parent != currentChild and length > 3) {
                return true;
            }
        }
    }
    
    return flag;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    unordered_map<int, vector<int>> graph;
    vector<vector<int>> value(n, vector<int>(m, -1));
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            value[i][j] = count++;
            // We identify every entry in the board matrix with unique integer
            // a[0][0] is identified with 0;
            // a[0][1] is identified with 1;
            // a[n - 1][m - 1] is identified with n * m - 1
        }
    }
    
    // Now we make a graph with those identified values
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            if(j - 1 >= 0 and board[i][j] == board[i][j - 1]) {
                graph[value[i][j]].push_back(value[i][j - 1]);
            }
            
            if(j + 1 < m and board[i][j] == board[i][j + 1]) {
                graph[value[i][j]].push_back(value[i][j + 1]);
            }
            
            if(i - 1 >= 0 and board[i][j] == board[i - 1][j]) {
                graph[value[i][j]].push_back(value[i - 1][j]);
            }
            
            if(i + 1 < n and board[i][j] == board[i + 1][j]) {
                graph[value[i][j]].push_back(value[i + 1][j]);
            }
        }
    }
    
    vector<bool> visited(count, false);
    
    for(int i = 0; i < count; i++) {
        if(!visited[i]) {
            bool cycle = dfs(graph, visited, i);
            if(cycle) {
                return true;
            }
        }
    }
    
    return false;
}
// Time Complexity : O(n * m)
// Auxillary Space : O(n * m)
