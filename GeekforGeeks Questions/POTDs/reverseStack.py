from typing import List

class Solution:
    def reverse(self,St): 
        #code here
        if len(St) == 0:
            return
        temp = St.pop()
        self.reverse(St)
        self.insertAtBottom(St,temp)

    def insertAtBottom(self,St,x):
        if len(St) == 0:
            St.append(x)
            return
        temp = St.pop()
        self.insertAtBottom(St,x)
        St.append(temp)

        