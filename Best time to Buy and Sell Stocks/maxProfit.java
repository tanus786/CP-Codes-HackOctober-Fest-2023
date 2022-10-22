class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        
        int maxProfit = 0;
        Stack<Integer> values = new Stack<>();
        values.push(prices[0]);
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < values.peek()){
                values.push(prices[i]);
            }
            else{
                maxProfit = Math.max(maxProfit, prices[i] - values.peek());
            }
        }
        return maxProfit;
    }
}
