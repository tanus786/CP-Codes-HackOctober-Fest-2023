class Solution:
    def componentValue(self, nums: List[int], edges: List[List[int]]) -> int:
        tot = sum(nums)
        dd = min(nums)
        n = len(nums)
        gr = [ [] for i in range(n) ]
        
        for a,b in edges:
            gr[a].append(b)
            gr[b].append(a)
        
        D = 0
        tr = 0 
        def check(u, p):
            nonlocal D, tr
            t = nums[u]
            for v in gr[u]:
                if v == p:
                    continue
                t += check(v, u)
            if t > D:
                return D + 1
            if t == D:
                tr += 1
                return 0
            return t
        
        for d in range(dd, tot):
            if tot % d:
                continue
            D = d
            tr = 0
            r = check(0, -1)
            if r == 0:
                return tr - 1
        return 0
