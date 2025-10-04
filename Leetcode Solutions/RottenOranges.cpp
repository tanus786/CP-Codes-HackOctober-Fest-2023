class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==2)
                    q.push({i, j});
        
        int x[] = {0, 0, -1, 1};
        int y[] = {-1, 1, 0, 0};
        
        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            bool anyRotten = false;
            while(size-->0)
            {
                pair<int, int> p = q.front();
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int i = p.first + x[k];
                    int j = p.second + y[k];
                    if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
                    {
                        anyRotten = true;
                        grid[i][j] = 2;
                        q.push({i, j});
                    }
                }
            }
            if(anyRotten)
                time++;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==1)
                    return -1;
        return time;
    }
};
