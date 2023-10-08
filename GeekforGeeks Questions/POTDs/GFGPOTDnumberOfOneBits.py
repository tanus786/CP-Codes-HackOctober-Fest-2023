class Solution:
	def setBits(self, N):
		# code here
        count = 0
        while N:
            N = N & (N-1)
            count += 1
        return count
        