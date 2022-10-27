def multiply(L: int):
    L = list(map(int, str(L)))
    result = 1
    for i in L:
        result *= i
    return result

def sum_all(L: int):
    L = list(map(int, str(L)))
    return sum(L)

def main():
    T = int(input())
    for t in range(1, T + 1):
        A, B = map(int, input().split())
        divisor_AB = {i for i in range(A, B+1) if multiply(i)%sum_all(i) == 0}
        print(f"Case #{str(t)}: {str(len(divisor_AB))}")
        
if __name__=="__main__":
    main()