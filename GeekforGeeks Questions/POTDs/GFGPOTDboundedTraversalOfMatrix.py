class Solution:
    
    #Function to return list of integers that form the boundary 
    #traversal of the matrix in a clockwise manner.
    def BoundaryTraversal(self,matrix, n, m):
        # code here
        ans=[]
        if n==1:
            for i in range(m):
                ans.append(matrix[0][i])
            return ans
        if m==1:
            for i in range(n):
                ans.append(matrix[i][0])
            return ans
        for i in range(m):
            ans.append(matrix[0][i])
        for i in range(1,n):
            ans.append(matrix[i][m-1])
        for i in range(m-2,-1,-1):
            ans.append(matrix[n-1][i])
        for i in range(n-2,0,-1):
            ans.append(matrix[i][0])
        return ans
        