from sys import stdin, setrecursionlimit
import queue

setrecursionlimit(10 ** 6)


#Following is the structure used to represent the Binary Tree Node
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None



def countNodesGreaterThanX(root, x) :
	#Your code goes here
    if root is None:
        return 0
    leftCount= countNodesGreaterThanX(root.left, x)
    rightCount= countNodesGreaterThanX(root.right, x)
    if root.data > x:
        return 1 + leftCount + rightCount
    return leftCount + rightCount































		



#Taking level-order input using fast I/O method
def takeInput():
    levelOrder = list(map(int, stdin.readline().strip().split(" ")))
    start = 0

    length = len(levelOrder)

    root = BinaryTreeNode(levelOrder[start])
    start += 1

    q = queue.Queue()
    q.put(root)

    while not q.empty():
        currentNode = q.get()

        leftChild = levelOrder[start]
        start += 1

        if leftChild != -1:
            leftNode = BinaryTreeNode(leftChild)
            currentNode.left =leftNode
            q.put(leftNode)

        rightChild = levelOrder[start]
        start += 1

        if rightChild != -1:
            rightNode = BinaryTreeNode(rightChild)
            currentNode.right =rightNode
            q.put(rightNode)

    return root

# Main
root = takeInput()
x = int(stdin.readline().strip())

count = countNodesGreaterThanX(root, x)
print(count)
