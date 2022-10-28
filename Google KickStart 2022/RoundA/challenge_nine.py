def Remain(N):
    if (N == 0):
        return 0
    elif (N % 9 == 0):
        return 9
    else:
       return (N % 9)
    
def main():
    T = int(input())
    for t in range(1, T + 1):
        N = int(input())
        x = 9-Remain(N)
        s = str(N)
        result = s + str(x)
        for i in range( 0 , len(s)):
            temp=s[0:i]+str(x)+s[i:len(s)]
            if(temp[0] == '0'):
                continue
            result=min(temp,result)
            
        print(f"Case #{str(t)}: {str(result)}")

if __name__=="__main__":
    main()
