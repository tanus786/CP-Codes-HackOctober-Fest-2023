class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(prices == null || n == 0) return 0;
        
        //  number of transactions = 4
        int[][] dp = new int[n+1][2];
                   
        for(int index = n-1; index >= 0; index--) {
            for(int buy = 0; buy < 2; buy++) {
                int profit = 0;
                
                if(buy == 1) {
                    // can buy
                    profit = Math.max(-prices[index]+dp[index+1][0], dp[index+1][1]);
                }
                else {
                    // sell
                    profit = Math.max(prices[index] + dp[index+2][1], dp[index+1][0]);
                }
                
                dp[index][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
}
