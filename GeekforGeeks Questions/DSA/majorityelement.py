class Solution:
    def majorityElement(self, nums: List[int]) -> int:
       #count the frequency of each element and store in a dictionary
        freq = {}
        for i in nums:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] = 1
        #find the element having frequency greater than n/2
        for i in freq:
            if freq[i] > len(nums)/2:
                return i
