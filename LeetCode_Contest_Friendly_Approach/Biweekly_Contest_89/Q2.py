class Solution(object):
    def productQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        p, a = [], [0] * len(queries)
        for i in range(30):
            if n >> i & 1:
                p.append(1 << i)
        dp = [[0] * len(p) for _ in p]
        for i in range(len(p)):
            v = 1
            for j in range(i, len(p)):
                v, dp[i][j] = v * p[j] % 1000000007, v * p[j] % 1000000007
        for i in range(len(queries)):
            a[i] = dp[queries[i][0]][queries[i][1]]
        return a
