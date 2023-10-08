class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equilibriumPoint(self,A, N):
        left_sum=0
        right_sum=0
        if N==1:
            return 1
        for i in range(1,N):
            right_sum+=A[i]
        for i in range(1,N):
            left_sum+=A[i-1]
            right_sum-=A[i]
            if left_sum==right_sum:
                return i+1
        return -1
#{
