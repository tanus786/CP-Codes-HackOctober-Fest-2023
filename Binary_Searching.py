#BINARY SEARCHING IN PYTHON
def binary_search(array, start, end, target):

    while(start<=end):

        mid = ( start + end )//2

        if target == arr[mid]:
            return mid
        
        elif target < arr[mid]:
            end = mid - 1
        
        else:
            start = mid + 1


start = 0
end = len(array) -1
# take array and target from user
# function call at the end
