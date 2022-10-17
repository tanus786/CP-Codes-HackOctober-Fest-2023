class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        N = len(nums)
        i0 = i_min = i_max = -1
        res = 0
        for i,a in enumerate(nums):
            if a < minK or a > maxK:
                i0 = i_min = i_max = i
            if a==minK:
                i_min = i
            if a==maxK:
                i_max = i
            if minK <= a <= maxK:
                res += max(min(i_min, i_max) - i0, 0)
        return res
