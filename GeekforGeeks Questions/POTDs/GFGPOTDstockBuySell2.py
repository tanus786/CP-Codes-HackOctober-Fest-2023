from typing import List


class Solution:
    def stockBuyAndSell(self, n : int, prices : List[int]) -> int:
        
        #initialize the profit to 0
        profit = 0

        #iterate through the list
        for i in range(1, n):
            #if the current price is greater than the previous price, add the difference to the profit
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]

        #return the profit
        return profit
        