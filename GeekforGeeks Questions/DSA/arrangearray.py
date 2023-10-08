class Solution:
    #Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    #with O(1) extra space.
    def arrange(self,arr, n):
        #Your code here
        for i in range(n):
            arr[i] += (arr[arr[i]]%n)*n
        for i in range(n):
            arr[i] = arr[i]//n
        return arr
        