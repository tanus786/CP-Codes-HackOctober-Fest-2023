n=int(input())
for i in range(n):
    a = int(input())
    #store all its factors in a list
    factors = []
    #find first three factors
    for j in range(1,a+1):
        if a%j==0:
            factors.append(j)
    factors.sort()
    #find length of list
    l = len(factors)
    if l-1==a and l<3:
        print(-1)
    else:
        #print 1st element and 1st prime number between 1 and l-2 and print l-2
        print(factors[0],factors[1],factors[l-2])
