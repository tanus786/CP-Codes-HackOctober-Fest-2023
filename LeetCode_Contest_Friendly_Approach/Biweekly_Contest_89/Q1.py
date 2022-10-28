class Solution:
    def countTime(self, time: str) -> int:
        lst = []
        number = 1
        for i in time:
            lst.append(i)
        if lst[0] == '?':
            if lst[1] == '?':
                number = number * 24
            elif int(lst[1]) < 4:
                number = number * 3
            else:
                number = number * 2
        if lst[1] == '?' and lst[0] != '?':
            if lst[0] == '2':
                number = number * 4
            else:
                number = number * 10
                
        if lst[3] == '?':
            number = number * 6
        if lst[4]=='?':
            number = number * 10
        
        return number
