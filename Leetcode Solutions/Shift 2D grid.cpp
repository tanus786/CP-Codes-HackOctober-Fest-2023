class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int a=grid.size(),b=grid[0].size();
        vector<vector<int>>val(a,vector<int>(b));
        int x;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                x=j+k;
                val[(i+(x/b))%a][x%b]=grid[i][j];
            }
        }
        return val;
    }
};
