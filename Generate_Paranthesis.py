class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        
        def helper(ans, s, left, right):
            if left==0 and right==0:
                ans.append(s)
                
            if left>0:
                helper(ans, s+'(', left-1, right)
                
            if right>0 and left<right:
                helper(ans, s+')', left, right-1)
        
        ans = []
        helper(ans, '', n, n)
        
        return ans
