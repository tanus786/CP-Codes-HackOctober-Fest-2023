class Solution:

    def longestPalinSubseq(self, S):
        # code herw
        n = len(S)

        dp = [[0 for i in range(n)] for j in range(n)]

        for i in range(n):
            dp[i][i] = 1

        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                if S[i] == S[j]:
                    dp[i][j] = 2 + dp[i+1][j-1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])

        return dp[0][n-1]
        