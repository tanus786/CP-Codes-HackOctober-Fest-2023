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
    fun Preorder(root: TreeNode?,list: MutableList<Int>){

        if(root==null)
        return

        list.add(root.`val`)
        Preorder(root.left,list)
        Preorder(root.right,list)

        return
    }
    fun preorderTraversal(root: TreeNode?): List<Int> {
        
        val ans = mutableListOf<Int>()
        Preorder(root,ans)
        return ans

    }
}
