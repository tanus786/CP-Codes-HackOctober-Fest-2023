class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        lst = []
        for i in set(nums):
            if (i * -1) in nums:
                lst.append(i)
        if lst == []:
            return -1
        return max(lst)
                
