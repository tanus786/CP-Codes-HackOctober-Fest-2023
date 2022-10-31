def findErrorNums(self, arr: List[int]) -> List[int]:
        
        n = len(arr)
        
        def Sum(arr):
            Sum = 0
            for ar in arr:
                Sum+=ar
            return Sum
        
        repeating = 0
        arr.sort()
        for i in range(n-1):
            if arr[i] == arr[i+1]:
                repeating = arr[i]
        
        actual_Sum = n*(n+1)//2
        arr_Sum = Sum(arr)
        
        missing = actual_Sum - (arr_Sum - repeating)
        
        return [repeating,missing]
