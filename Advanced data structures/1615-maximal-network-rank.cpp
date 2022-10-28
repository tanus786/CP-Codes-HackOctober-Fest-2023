class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>graph(n);
        for(auto &road:roads)
        {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int count=graph[i].size()+graph[j].size();
                if(graph[j].count(i))count--;
                
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
