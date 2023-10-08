class Solution:

	def valueEqualToIndex(self,arr, n):
		# code here
        values=[]
        for i in range (n):
            if arr[i]==i+1:
                values.append(arr[i])
        return values
        