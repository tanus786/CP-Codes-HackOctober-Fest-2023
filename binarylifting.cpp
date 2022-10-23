#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<vector<int>> ancestor;
int main() {
  int n; cin>>n; // n is the number of nodes numbered 0 to n-1
  int LOG = log2(n);
  parent.assign(n, 0);  
  ancestor.assign(n, vector<int>(LOG+2));
  // Assuming node 0 is the root of the tree
  parent[0] = 0;
  // Assuming next n-1 lines contain edges in format: parent_node child_node
  for(int i=0; i<n-1; ++i) {
    int p, c; cin>>p>>c;
    parent[c] = p;  
  }
  for(int i=0; i<n; ++i) ancestor[i][0] = parent[i];
  for(int x=1; x<=LOG+1; ++x) ancestor[0][x] = 0;
  for(int x=1; x<=LOG+1; ++x) {
    for(int i=0; i<n; ++i) {
      ancestor[i][x] = ancestor[ancestor[i][x-1]][x-1];
    }
  }
  int q; cin>>q; // Number of Queries
  while(q--) {
    int node, k; cin>>node>>k;
    for(int i=LOG+1; i>=0; i--) {
      if( k & (1<<i) ) node = ancestor[node][i];  
    }  
    cout<<node<<endl;
  }
}