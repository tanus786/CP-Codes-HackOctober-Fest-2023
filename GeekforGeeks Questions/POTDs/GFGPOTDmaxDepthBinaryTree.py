class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

class Solution:
    def maxDepth(self,root):
        if root is None:
            return 0
        else:
            lDepth = self.maxDepth(root.left)
            rDepth = self.maxDepth(root.right)

            if lDepth > rDepth:
                return lDepth + 1
            else:
                return rDepth + 1

