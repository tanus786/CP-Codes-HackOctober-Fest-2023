def linear_search(array, N, target):
    # Manually taking values of Array and Target element

    for i in range(0, N):
        if target == array[i]:
            return i
    return -1
    # if element is absent in the array, return -1

N = len(array)
# function call at the end
