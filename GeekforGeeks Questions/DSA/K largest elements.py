#take two numbers input in one line
n,k = map(int,input().split())
#n is the length of array
#k is the number of largest elements to be found
#take array input in one line
arr = list(map(int,input().split()))


#function to find k largest elements
def kLargest(arr, k):
    #sort the array in descending order
    arr.sort(reverse=True)
    #return the k largest elements
    return arr[:k]

#call the function and print the result
print(kLargest(arr,k))
