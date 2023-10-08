#User function Template for python3


#Function to modify the matrix such that if a matrix cell matrix[i][j]
#is 1 then all the cells in its ith row and jth column will become 1.
def booleanMatrix(matrix):
    r=len(matrix)
    c=len(matrix[0])
    row=[0]*r
    col=[0]*c
    for i in range(r):
        for j in range(c):
            if matrix[i][j]==1:
                row[i]=1
                col[j]=1
    for i in range(r):
        for j in range(c):
            if row[i]==1 or col[j]==1:
                matrix[i][j]=1
    return matrix
    