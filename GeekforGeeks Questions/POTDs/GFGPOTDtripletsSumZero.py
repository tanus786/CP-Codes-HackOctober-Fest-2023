class Solution:
    #Function to find triplets with zero sum.    
    def findTriplets(self, arr, n):
        #find the triplet that sum to zero
        #code here
        #and return 1 if found else 0
        arr.sort()
        for i in range(n-2):
            l=i+1
            r=n-1
            while(l<r):
                if(arr[i]+arr[l]+arr[r]==0):
                    return 1
                elif(arr[i]+arr[l]+arr[r]<0):
                    l+=1
                else:
                    r-=1
        return 0
        