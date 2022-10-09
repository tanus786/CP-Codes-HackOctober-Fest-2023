class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        for i in range(len(nums)-1):
            a = target-nums[i]
            if a in nums[i+1:]:
                ans.append(i)
                ans.append(i+nums[i+1:].index(a)+1)
                break
        return ans
