/*
Coding Ninjas
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000

Time Limit: 1 second

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output 1:
1
*/

#include<vector>
#include<string>
bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string s, int i, int j, int n, int m) {
    // base case
    if(board[i][j] != s[0]) {
        return false;
    }
    
    // If Last letter of string is found then we return
    if(s.length() == 1) {
        return true;
    }
    
    visited[i][j] = true;
    bool ans1 = false, ans2 = false, ans3 = false, ans4 = false, ans5 = false, ans6 = false, ans7 = false, ans8 = false;
    
    //For aij as the current we call in 8 direction
    
    // a[i - 1[j - 1]
    if(i - 1 >= 0 and j - 1 >= 0) {
        if(!visited[i - 1][j - 1]) {
            ans1 = helper(board, visited, s.substr(1), i - 1, j - 1, n, m);
        }
    }
    
    //a[i - 1][j]
    if(i - 1 >= 0) {
        if(!visited[i - 1][j]) {
            ans2 = helper(board, visited, s.substr(1), i - 1, j, n, m);
        }
    }
    
    //a[i - 1][j + 1]
    if(i - 1 >= 0 and j + 1 < m) {
        if(!visited[i - 1][j + 1]) {
            ans3 = helper(board, visited, s.substr(1), i - 1, j + 1, n, m);
        }
    }
    
    //a[i][j - 1]
    if(j - 1 >= 0) {
        if(!visited[i][j - 1]) {
            ans4 = helper(board, visited, s.substr(1), i, j - 1, n, m);
        }
    }
    
    //a[i][j + 1]
    if(j + 1 < m) {
        if(!visited[i][j + 1]) {
            ans5 = helper(board, visited, s.substr(1), i, j + 1, n, m);
        }
    }
    
    //a[i + 1][j - 1]
    if(i + 1 < n and j - 1 >= 0) {
        if(!visited[i + 1][j - 1]) {
            ans6 = helper(board, visited, s.substr(1), i + 1, j - 1, n, m);
        }
    }
    
    //a[i + 1][j]
    if(i + 1 < n) {
        if(!visited[i + 1][j]) {
            ans7 = helper(board, visited, s.substr(1), i + 1, j, n, m);
        }
    }
    
    //a[i + 1][j + 1]
    if(i + 1 < n  and j + 1 < m) {
        if(!visited[i + 1][j + 1]) {
            ans8 = helper(board, visited, s.substr(1), i + 1, j + 1, n, m);
        }
    }
    
    if(ans1 or ans2 or ans3 or ans4 or ans5 or ans6 or ans7 or ans8) {
        return true;
    } else {
        visited[i][j] = false;
        return false;
    }
    
}

bool hasPath(vector<vector<char>>& board, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string s = "CODINGNINJA";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'C'){
                bool path = helper(board, visited, s, i, j, n, m);
                if(path) {
                    return true;
                }
            }
        }
    }
    
    return false;
}
// Time Complexity : O(nm)
// Auxillary Space : O(mn)
