n=int(input())
for i in range(n):
    #three integers
    a,b,c=map(int,input().split())
    if (c==a+b):
        print("YES")
    else:
        print("NO")
    
