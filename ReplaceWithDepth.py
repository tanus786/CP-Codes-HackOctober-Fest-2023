from sys import stdin,setrecursionlimit
setrecursionlimit(10**6)

class treeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

def replacewithDepthUtility(root, value):
    if root is None:
        return
    root.data = value
    childCount = len(root.children)
    for i in range(childCount):
        replacewithDepthUtility(root.children[i], value+1)

def replacewithDepth(tree):
    #############################
    # PLEASE ADD YOUR CODE HERE #
    #############################
    replacewithDepthUtility(tree, 0)




def createLevelWiseTree(arr):
    root = treeNode(int(arr[0]))
    q = [root]
    size = len(arr)
    i = 1
    while i<size:
        parent = q.pop(0)
        childCount = int(arr[i])
        i += 1
        for j in range(0,childCount):
            temp = treeNode(int(arr[i+j]))
            parent.children.append(temp)
            q.append(temp)
        i += childCount
    return root

def printLevelAtNewLine(tree):
    q = [tree]
    newq = []
    while q:
        parent = q.pop(0)
        print(parent.data, end=' ')
        for child in parent.children:
            newq.append(child)
        if len(q)==0:
            q = newq
            newq = []
            print()  # Move to next Line

# Main
arr = list(int(x) for x in stdin.readline().strip().split())
tree = createLevelWiseTree(arr)
replacewithDepth(tree)
printLevelAtNewLine(tree)
