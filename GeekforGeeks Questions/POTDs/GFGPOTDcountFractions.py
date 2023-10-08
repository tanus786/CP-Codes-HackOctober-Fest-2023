class Solution:
    def countFractions(self, n, numerator, denominator):
        # Your code here
        #numerator is a list containing all the numerators
        #denominator is a list containing all the denominators
        #find the number of pairs such that sum of their fractions is 1
        #return the count
        count = 0
        for i in range(n):
            for j in range(i+1,n):
                if numerator[i]*denominator[j] + numerator[j]*denominator[i] == denominator[i]*denominator[j]:
                    count += 1
        return count
        