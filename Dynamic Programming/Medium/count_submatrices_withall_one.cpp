class Solution {
public:
    int dp[301][301];
    int rec(vector<vector<int>>& matrix,int i,int j){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==0)
            return 0;
        int ans=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=rec(matrix,i+1,j+1),r=rec(matrix,i,j+1),t=rec(matrix,i+1,j);
        ans=1+min(l,min(r,t));
        return dp[i][j]=ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1)
                    ans+=rec(matrix,i,j);
            }
        }
        return ans;
    }
};