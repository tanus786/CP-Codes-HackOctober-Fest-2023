class Solution:
    
    #Function to find the smallest positive number missing from the array.
    def missingNumber(self,arr,n):
        #Your code here
        pos_arr = []
        for num in arr:
            if num > 0:
                pos_arr.append(num)
    
    # Mark visited numbers by negating the corresponding index
        for num in pos_arr:
            index = abs(num) - 1
            if index < len(pos_arr):
                pos_arr[index] = -abs(pos_arr[index])
    
    # Find the first positive number
        for i in range(len(pos_arr)):
            if pos_arr[i] > 0:
                return i + 1
    
    # If all positive numbers are present, return the next number
        return len(pos_arr) + 1