class Solution:
    def nextHappy (self, N):
        # code here
        i=N+1
        while True:
            N=i
            while True:
                sum=0
                while N!=0:
                    sum+=(N%10)**2
                    N=int(N/10)
                if sum<10:
                    if sum in [1,7]:
                        return i
                    else:
                        break
                N=sum
                sum=0
            i+=1
