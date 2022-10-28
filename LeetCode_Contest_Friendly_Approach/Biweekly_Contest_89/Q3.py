class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        l,r = -int(1e10),int(1e10)
        
        
        def check(target):
            if nums[0] > target:
                return False
            owe = target - nums[0]
            for i in nums[1:]:
                if i > target:
                    diff = i - target
                    if owe < diff:
                        return False
                    owe-=diff
                else:
                    owe += target - i
            return True
        
        while l<r:
            mid = (l+r)//2
            if check(mid):
                r = mid
                
            else:
                l = mid+1
        
        return l
            
