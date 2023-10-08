class Solution:
    def deleteMid(self, s, si):
        i = 0
        n = si // 2
        s1 = []

        while i < n:
            a = s[-1]
            s.pop()
            s1.append(a)
            i += 1

        s.pop()

        while s1:
            a = s1[-1]
            s1.pop()
            s.append(a)
