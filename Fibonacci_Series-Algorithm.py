#Fibonacci Series is a pattern of numbers where each number results from adding the last two consecutive numbers. 


#Using iteration
def fib_iter(n):
    a=1
    b=1
    if n==1:
        print('0')
    elif n==2:
        print('0','1')
    else:
        print("Iterative Approach: ", end=' ')
        print('0',a,b,end=' ')
        for i in range(n-3):
            total = a + b
            b=a
            a= total
            print(total,end=' ')
        print()
        return b
         
fib_iter(5)

#Using Recursion
def fib_rec(n):
    if n == 1:
        return [0]
    elif n == 2:
        return [0,1]
    else:
        x = fib_rec(n-1)
        # the new element the sum of the last two elements
        x.append(sum(x[:-3:-1]))
        return x
x=fib_rec(5)
print(x)