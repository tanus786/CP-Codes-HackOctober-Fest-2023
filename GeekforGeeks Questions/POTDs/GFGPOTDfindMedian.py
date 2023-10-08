def findMedian(root):
    # code here
    # return the median
    arr = []
    inorder(root, arr)
    n = len(arr)
    if n % 2 == 0:
        return (arr[n//2] + arr[n//2 - 1]) / 2
    else:
        return arr[n//2]

def inorder(root, arr):
    if root:
        inorder(root.left, arr)
        arr.append(root.data)
        inorder(root.right, arr)


# Driver Code

# Path: GFGPOTDfindMedian.py
