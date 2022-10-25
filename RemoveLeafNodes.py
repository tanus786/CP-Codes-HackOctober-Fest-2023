import queue 
class treeNode:
    def __init__(self, data):
        self.data = data
        self.children = []
    def __str__(self):
        return str(self.data)

def removeLeafNodes(root):
    #Implement Your Code Here
    pass
    if(root==None): return None #if root is None return None
    if(len(root.children)==0):return None #if root itself is leaf return None
    # if root.children is a leaf node
    # then delete it from children vector
    i = 0
    while i < len(root.children):
        child = root.children[i]
 
        # if it is  a leaf
        if (len(child.children) == 0):
 
            # shifting the vector to left
            # after the point i
            for j in range(i, len(root.children) - 1):
                root.children[j] = root.children[j + 1]
 
            # delete the last element
            root.children.pop()
            i -= 1
        i += 1
 
    # Remove all leaf node
    # of children of root
    for i in range(len(root.children)):
 
        # call function for root.children
        root.children[i] = removeLeafNodes(root.children[i])
    return root
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

def printLevelWiseTree(root):
    q = queue.Queue()
    q.put(root)
    q.put(None)
    
    while q.empty() is False:
        front = q.get()
        if front is None:
            if q.empty():
                return
            else:
                print()
                q.put(None)
        else:
            print(front.data,end= ' ')
            for child in front.children:
                q.put(child)
            
        
    
    
# Main
arr = list(int(x) for x in input().strip().split(' '))
root = createLevelWiseTree(arr)
removeLeafNodes(root)
printLevelWiseTree(root)
