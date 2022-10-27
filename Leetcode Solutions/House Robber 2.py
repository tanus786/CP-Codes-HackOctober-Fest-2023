


class Solution:
    def rob(self, nums):
        def rob_helper(nums):
            dp1, dp2 = 0, 0
            for num in nums:
                dp1, dp2 = dp2, max(dp1 + num, dp2)          
            return dp2
    
        return max(nums[0] + rob_helper(nums[2:-1]), rob_helper(nums[1:])
