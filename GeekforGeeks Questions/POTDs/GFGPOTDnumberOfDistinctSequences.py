class Solution:
	def distinctSubsequences(self, S):
		# code here
        n = len(S)
        dp = [0 for i in range(n+1)]
        dp[0] = 1
        last = {}
        for i in range(1, n+1):
            dp[i] = 2*dp[i-1]
            if S[i-1] in last:
                dp[i] -= dp[last[S[i-1]]-1]
            last[S[i-1]] = i
        return dp[n]%1000000007
        