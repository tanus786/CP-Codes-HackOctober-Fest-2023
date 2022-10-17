class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        if num == 0:
            return True
        if num < 0:
            return False
        for i in range(0 , num):
            rev = str(i)[::-1]
            revv = int(rev)
            if revv + i == num:
                return True
    
        return False
