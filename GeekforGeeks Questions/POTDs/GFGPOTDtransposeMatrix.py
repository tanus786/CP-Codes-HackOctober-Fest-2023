class Solution:
    def transpose(self, matrix, n):
        # code here
        for i in range(n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        return matrix
        