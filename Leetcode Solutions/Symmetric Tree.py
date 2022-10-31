def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def helper(root1,root2):
            if not root1 and not root2:
                return True
            if root1 and root2:
                if root1.val != root2.val:
                    return False
                isLsymm = helper(root1.left,root2.right)
                isRsymm = helper(root1.right,root2.left)
                
                return isLsymm and isRsymm
                
            
        if not root:
            return True
        res = helper(root.left,root.right)
        return res
