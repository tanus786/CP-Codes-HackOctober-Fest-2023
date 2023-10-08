class Solution:
    #Back-end complete function Template for Python 3
    
    #Function to find the leaders in the array.
    def leaders(self, A, N):
        #Code here
        max = A[N-1]
        leaders = []
        leaders.append(max)
        for i in range(N-2,-1,-1):
            if A[i]>=max:
                max = A[i]
                leaders.append(max)
        leaders.reverse()
        return leaders
        