#User function Template for python3


class Solution:
    def firstElementKTime(self,  a, n, k):

        #find the first element that occurs k times

        #code here
        for i in range(n):
            if a.count(a[i])==k:
                return a[i]
        return -1
        