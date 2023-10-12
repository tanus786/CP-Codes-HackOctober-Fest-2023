/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun Inorder(root: TreeNode?,list: MutableList<Int>){
        
        if(root==null)
        return;

        Inorder(root.left,list)
        list.add(root.`val`)
        Inorder(root.right,list)

        return;
    }
    fun inorderTraversal(root: TreeNode?): List<Int> {
        
        val ans = mutableListOf<Int>()
        Inorder(root,ans)
        return ans
    }
}
