#include<bits/stdc++.h>
using namespace std;
int n, m;
// A MORE OPTIMAL METHOD
// IN A LEXICOGRAPHICAL MANNER
string dir= "DLRU";
int di[]={1, 0, -1, 0};
int dj[]={0, 1, 0, -1};

void findpath(int i, int j, string s, vector<vector<int>>&vis){
if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1) return ;
if(i==n-1 && j==m-1){
    cout << s << endl;
    return ;
}
vis[i][j]=1;
for(int x=0; x<4; x++){
    s+=dir[x];
    findpath(i+di[x], j+dj[x], s, vis);
    s.pop_back();
}
vis[i][j]=0;
}

int main(){
cin >> m >> n;
vector<vector<int>> vis(n,vector<int>(m,0));
findpath(0,0,"", vis);
}
