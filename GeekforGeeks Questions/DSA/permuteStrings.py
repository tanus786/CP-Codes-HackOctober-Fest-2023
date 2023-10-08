class Solution:
    def permutation(self,s):
        #s is a string
        if len(s) == 0:
            return []
        if len(s) == 1:
            return [s]
        res = []
        for i in range(len(s)):
            for j in self.permutation(s[:i] + s[i+1:]):
                res.append(s[i] + j)
        return res
        