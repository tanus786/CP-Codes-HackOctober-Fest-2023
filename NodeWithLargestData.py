class BinaryTreeNode:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
def treeInput():
    rootData = int(input())
    if rootData == -1:
        return None
    root = BinaryTreeNode(rootData)
    leftTree = treeInput()
    rightTree = treeInput()
    root.left = leftTree
    root.right = rightTree
    return root

def PrintTree(root):
    if root == None:
        return
    print(root.data,end= ":")
    if root.left is not None:
        print("L", root.left.data, end = ",")
    if root.right is not None:
        print("R", root.right.data, end = "")
    print()
    PrintTree(root.left)
    PrintTree(root.right)

def LargestData(root):
    if root is None:
        return -1       #Assuming that the tree contains all positive numbers
                        #Ideally we would have returned negative infinity
    leftMax = LargestData(root.left)
    rightMax = LargestData(root.right)
    largest =  max(leftMax, root.data, rightMax)
    return largest
root = treeInput()
PrintTree(root)
print(LargestData(root))
