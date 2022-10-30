t= int(input())
for _ in range(t):
    n=int(input())
    arr= list(map(int,input().strip().split(" ")))[:n]
    c=[]
    flag =0
    for i in range(n//2):
        if arr[n-1-i]-arr[i]>=0:
            c.append(arr[n-1-i]-arr[i])
        else:
            flag=1 
            
    d=c.copy()
    d=sorted(d,reverse=True)
    if flag==0 and c==d:
        print(max(c))
    else:
        print(-1)