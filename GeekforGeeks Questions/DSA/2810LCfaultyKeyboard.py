class Solution:
    def finalString(self, s: str) -> str:
        while "i" in s:
            index=s.index("i")

            #first half and second half
            first=s[:index][::-1]
            second=s[index+1:]

            s="".join([first,second])
        return s