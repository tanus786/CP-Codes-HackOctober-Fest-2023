from typing import List


class Solution:
    def isFrequencyUnique(self, n: int, arr: List[int]) -> bool:
        freq = {}
        for i in arr:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] = 1
        return len(set(freq.values())) == len(freq)
