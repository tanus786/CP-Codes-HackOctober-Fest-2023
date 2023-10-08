
class Solution:
    #Function to reverse the queue.
    def rev(self, q):
        #add code here
        if len(q) == 0:
            return
        x = q.pop(0)
        self.rev(q)
        q.append(x)
        return q
        