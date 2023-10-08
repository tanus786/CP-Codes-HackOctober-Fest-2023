class Solution:
    
    #Function to merge the arrays.
    def merge(self,arr1,arr2,n,m):
        arr3=[]
        #add all elements of arr1 and arr2 to arr3
        for i in range(n):
            arr3.append(arr1[i])
        for i in range(m):
            arr3.append(arr2[i])
        #sort arr3
        arr3.sort()
        #replace elements of arr1 and arr2 with elements of arr3
        for i in range(n):
            arr1[i]=arr3[i]
        for i in range(m):
            arr2[i]=arr3[n+i]
        #return arr1 and arr2
        return arr1,arr2