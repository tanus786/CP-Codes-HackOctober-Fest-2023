class Solution:
    def romanToDecimal(self, S): 
        # code here
        roman={ 'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        i=0
        ans=0
        while i<len(S):
            if i+1<len(S) and roman[S[i]]<roman[S[i+1]]:
                ans+=roman[S[i+1]]-roman[S[i]]
                i+=2
            else:
                ans+=roman[S[i]]
                i+=1    
        return ansx 