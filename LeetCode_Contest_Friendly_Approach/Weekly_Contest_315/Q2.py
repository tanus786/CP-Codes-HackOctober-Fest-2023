class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        lst = nums
        rev = 0
        for n in set(nums):
            while(n > 0):
                a = n % 10
                rev = rev * 10 + a
                n = n // 10
            lst.append(rev)
            rev = 0
        return len(set(lst))
