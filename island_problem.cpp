#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &mat,int n,int m)
{
    if(i<0 or j<0 or i>=n or j>=m) return;
    if(mat[i][j]==0) return;
    if(!vis[i][j])
    {
        vis[i][j]=1;
        dfs(i+1,j,vis,mat,n,m);
        dfs(i-1,j,vis,mat,n,m);
        dfs(i,j+1,vis,mat,n,m);
        dfs(i,j-1,vis,mat,n,m);
        dfs(i+1,j+1,vis,mat,n,m);
        dfs(i-1,j-1,vis,mat,n,m);
        dfs(i+1,j-1,vis,mat,n,m);
        dfs(i-1,j+1,vis,mat,n,m);
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat;
    for(int i=0;i<n;i++)
    { vector<int> v;
        for(int j=0;j<m;j++)
        { int x;cin>>x;
            v.push_back(x);
        }
        mat.push_back(v);
    }
    vector<vector<int>> vis;
 for(int i=0;i<n;i++)
 {  vector<int> v;
     for(int j=0;j<m;j++)
     {  
v.push_back(0);
     }
     vis.push_back(v);
 }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&mat[i][j]==1)
            {
                dfs(i,j,vis,mat,n,m);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}/*void dfs(vector<vector<int>> &vis,vector<vector<int>> &mat,int n,int m,int i,int j)
{
    if(i<0 || j<0 || j>=m||i>=n)
    return;
    if(mat[i][j]==0) return;
    if(!vis[i][j]){
    dfs(vis,mat,n,m,i+1,j);
    
    dfs(vis,mat,n,m,i,j+1);
    
    dfs(vis,mat,n,m,i-1,j);
    
    dfs(vis,mat,n,m,i,j-1);
    
    dfs(vis,mat,n,m,i+1,j+1);
    dfs(vis,mat,n,m,i+1,j-1);
    
    dfs(vis,mat,n,m,i-1,j-1);
    
    dfs(vis,mat,n,m,i-1,j+1);
    
    }
    
}
int countIslands(int M[][COL], int n, int m) {
    // your code goes here
    vector<vector<int>> mat;
    for(int i=0;i<n;i++)
    { vector<int> d;
        for(int j=0;j<m;j++)
        {
            d.push_back(M[i][j]);
        }
        mat.push_back(d);
    }
    vector<vector<int>> vis;
     for(int i=0;i<n;i++)
    { vector<int> d;
        for(int j=0;j<m;j++)
        {
            d.push_back(0);
        }
        vis.push_back(d);
    }
    int ans=0;
     for(int i=0;i<n;i++)
    { 
        for(int j=0;j<m;j++)
        {
           if(!vis[i][j]&&mat[i][j]==1)
           {
              dfs(vis,mat,n,m,i,j)
              ans++;
           }
        }
    
    }
    return ans;
}
*/