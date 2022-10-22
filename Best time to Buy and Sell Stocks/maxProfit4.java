class Solution {
    public int maxProfit(int B, int[] prices) {
        int n = prices.length;
        if(prices == null || n==0) return 0;
        
        // number of transactions = 2*B
        int[][] dp = new int[n+1][2*B+1];
                   
        for(int index=n-1; index>= 0; index--){
            for(int transaction=2*B-1; transaction>=0; transaction--){
                int profit = 0;
                
                if(transaction % 2 == 0){
                    // even transaction = buy
                    profit = Math.max(-prices[index]+dp[index+1][transaction+1], dp[index+1][transaction]);
                }
                else{
                    // odd transaction = sell
                    profit = Math.max(prices[index] + dp[index+1][transaction+1] , dp[index+1][transaction]);
                }
                
                dp[index][transaction] = profit;
            }
        }
        
        return dp[0][0];
    }
}
