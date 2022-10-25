#include<iostream>
#include<queue>
using namespace std;
//D L R U : lexicographically
void solve(int row, int col, vector<vector<int>>&paths, vector<vector<int>>&visited, string op, int n){
    if(row==n-1 && col==n-1){
        for(auto it:op){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    //downward
    if(row+1<n && !visited[row+1][col] && paths[row+1][col]==1){
        visited[row][col]=1;
        solve(row+1,col,paths,visited,op+'D',n);
        visited[row][col]=0;
    }
    //leftward
    if(col-1>=0 && !visited[row][col-1] && paths[row][col-1]==1){
        visited[row][col]=1;
        solve(row,col-1,paths,visited,op+'L',n);
        visited[row][col]=0;
    }
    //righward
    if(col+1<n && !visited[row][col+1] && paths[row][col+1]==1){
        visited[row][col]=1;
        solve(row,col+1,paths,visited,op+'R',n);
        visited[row][col]=0;
    }
    //upward
    if(row-1>=0 && !visited[row-1][col] && paths[row-1][col]==1){
        visited[row][col]=1;
        solve(row-1,col,paths,visited,op+'U',n);
        visited[row][col]=0;
    }
}
int main(){
    vector<vector<int>>paths = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n=4;
    vector<vector<int>>visited(n,vector<int>(n,0));  //remember
    string op = "";
    if(paths[0][0]==1){
        solve(0,0,paths,visited,op,n);
    }
    else{
        cout<<"No route possible";
    }

}