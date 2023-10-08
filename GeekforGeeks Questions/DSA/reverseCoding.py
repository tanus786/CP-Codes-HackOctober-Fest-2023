class Solution:
    def sumOfNaturals(self, n):
        if n == 1:
            return 1
        #answer can be large so return modulo 10^9+7
        return (n + self.sumOfNaturals(n-1)) % (10**9 + 7)
        