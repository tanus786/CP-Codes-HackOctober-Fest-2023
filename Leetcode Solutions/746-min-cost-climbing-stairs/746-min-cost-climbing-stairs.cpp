class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size()+1,0);
        for(int i=0;i<cost.size();i++) dp[i] = cost[i];
        
        for(int i=dp.size()-3;i>=0;i--){
            dp[i] = min(dp[i]+dp[i+2],dp[i]+dp[i+1]);
        }
        
        return min(dp[0],dp[1]);
    }
};