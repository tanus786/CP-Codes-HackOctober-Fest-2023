class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs.sort()
        d=[]
        for i in strs:
            d.append("".join(sorted(i)))
        d1={}
        for i in range(len(d)):
            if d[i] not in d1:
                d1[d[i]]=[strs[i]]
            else:
                d1[d[i]].append(strs[i])
        return d1.values()
        