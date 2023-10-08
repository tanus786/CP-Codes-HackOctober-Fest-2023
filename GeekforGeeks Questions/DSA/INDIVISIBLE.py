n=int(input())
for i in range(n):
    #three integers
    a,b,c=map(int,input().split())
    #find a positive numbers less than 100 and doesnt divides a b c
    for j in range(1,100):
        if a%j!=0 and b%j!=0 and c%j!=0:
            print(j)
            break


    
