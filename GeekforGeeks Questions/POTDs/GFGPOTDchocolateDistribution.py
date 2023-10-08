class Solution:

    def findMinDiff(self, A,N,M):

        # code here
        #N size of array
        #M no of students
        A.sort()
        if N == M:
            return A[-1] - A[0]
        else:
            min_diff = float('inf')
            for i in range(N-M+1):
                min_diff = min(min_diff, A[i+M-1] - A[i])
            return min_diff
            