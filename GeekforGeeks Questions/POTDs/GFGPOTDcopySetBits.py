class Solution:
    def setSetBit(self, x, y, l, r):
        #l and r are range and x and y are numbers
        for i in range(l, r+1):
            if (y & (1 << (i-1))) != 0:
                x = x | (1 << (i-1))
        return x
        