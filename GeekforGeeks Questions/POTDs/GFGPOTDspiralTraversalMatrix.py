class Solution:
    def findK(self, a, n, m, k):
        # Write Your Code here
        #spiral traversal of matrix and find kth element

        #initializing variables
        top = 0
        bottom = n-1
        left = 0
        right = m-1
        dir = 0
        count = 0

        while(top <= bottom and left <= right):
            if(dir == 0):
                for i in range(left, right+1):
                    count += 1
                    if(count == k):
                        return a[top][i]
                top += 1
                dir = 1
            elif(dir == 1):
                for i in range(top, bottom+1):
                    count += 1
                    if(count == k):
                        return a[i][right]
                right -= 1
                dir = 2
            elif(dir == 2):
                for i in range(right, left-1, -1):
                    count += 1
                    if(count == k):
                        return a[bottom][i]
                bottom -= 1
                dir = 3
            elif(dir == 3):
                for i in range(bottom, top-1, -1):
                    count += 1
                    if(count == k):
                        return a[i][left]
                left += 1
                dir = 0
        return -1
        