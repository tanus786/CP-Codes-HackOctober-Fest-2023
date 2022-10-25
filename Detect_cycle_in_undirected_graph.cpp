#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // int order[100005];
    stack<int>s;
    int vis[100005];
    void dfs(int v,vector<int>adj[])
    {
        vis[v]=1;
        // order[v]=1;
        for(auto it:adj[v])
        {
            if(!vis[it])
            {
                dfs(it,adj);
            }
            // else if(order[it])return true;
        }
        // order[v]=0;
        s.push(v);
        // return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        memset(vis,0,sizeof(vis));
        // memset(order,0,sizeof(order));
        // s.clear();
        unordered_map<int,int>pos;
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                // s.clear();
                dfs(i,adj);
                
            }
        }
        while(!s.empty()){
                    pos[s.top()]=count;
                    count++;
                    s.pop();
        }
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                if(pos[i]>pos[it]){
                    return true;
                }
            }
        }

    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends