class Solution:
    def isDivisible(self, s):
        # s is a binary number check if it is divisible by 3
        # convert the binary number to decimal
        s = int(s, 2)
        # check if the decimal number is divisible by 3
        if s % 3 == 0:
            return 1
        else:
            return 0


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        print(ob.isDivisible(s))
# } Driver Code Ends
