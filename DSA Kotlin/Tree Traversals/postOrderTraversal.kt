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
    fun Postorder(root: TreeNode?,ans: MutableList<Int>){

        if(root==null)
        return

        Postorder(root.left,ans)
        Postorder(root.right,ans)
        ans.add(root.`val`)

        return
    }
    fun postorderTraversal(root: TreeNode?): List<Int> {
        
        val ans = mutableListOf<Int>()
        Postorder(root,ans)
        return ans

    }
}