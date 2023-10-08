class Solution:
    def largestPrimeFactor (self, N):
        # code here
        #O(sqrt(N))
        if N == 1:
            return 1
        while N % 2 == 0:
            N //= 2
        if N == 1:
            return 2
        for i in range(3, int(N ** 0.5) + 1, 2):
            while N % i == 0:
                N //= i
            if N == 1:
                return i
        return N
        