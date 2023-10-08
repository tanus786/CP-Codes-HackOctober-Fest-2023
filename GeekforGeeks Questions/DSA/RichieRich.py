class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:

        # 1. Sort the array
        nums.sort()
         # 2. Initialize the result
        result = 0
    # 3. Initialize two pointers, one at the start and one at the end
        left = 0
        right = len(nums) - 1
    # 4. Iterate until the two pointers meet and then increment the left pointer 
        while left < right:
            if nums[left] + nums[right] < lower:
                left += 1
            elif nums[left] + nums[right] > upper:
                right -= 1
                #if right has reached the left pointer, increment the left pointer 
                if right == left:
                    left += 1
                    #else if left has reached the right pointer, decrement the right pointer
            else:
                result += 1
                left += 1
                if left == right:
                    right -= 1
        return result
        