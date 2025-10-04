def maxSlidingWindow(self, arr: List[int], k: int) -> List[int]:
        
        n = len(arr)
        
        q = []
        res = []
        
        for i in range(n):
            
            if q and q[0] == i - k:
                q.pop(0)
            
            while q and arr[q[-1]] <= arr[i]:
                q.pop()
            
            q.append(i)
            
            if i >= k-1:
                res.append(arr[q[0]])
            
        return res
