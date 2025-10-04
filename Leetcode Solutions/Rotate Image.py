def rotate(self, arr: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(arr)
        
        # Transpose
        for i in range(n):
            for j in range(i+1,n):
                arr[i][j],arr[j][i] = arr[j][i],arr[i][j]
        
        # Reverse
        for i in range(n):
            left = 0
            right = n-1
            while left < right:
                arr[i][left],arr[i][right] = arr[i][right],arr[i][left]
                left+=1
                right-=1
        return arr
