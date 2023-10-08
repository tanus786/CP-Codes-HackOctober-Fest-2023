class Solution:

	def print2largest(self,arr, n):
		#find distinct elements
        arr=list(set(arr))
        arr.sort()
        if len(arr)<2:
            return -1
        return arr[-2]

        