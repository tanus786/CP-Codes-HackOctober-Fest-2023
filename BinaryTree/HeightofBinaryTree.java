public class Solution {
    public static int heightOfBinaryTree(TreeNode root) {
        // Write your code here.
        if(root==null){
            return 0;
        }

        int outputleft=heightOfBinaryTree(root.left);
        int outputright=heightOfBinaryTree(root.right);
        if(outputleft>outputright){
            return outputleft+1;
        }else{
            return outputright+1;
        }
    }
}

The time complexity of the given code is O(n), where n is the number of nodes in the binary tree. This is because the code recursively traverses the entire tree to calculate the height.
The space complexity of the code is also O(n), where n is the number of nodes in the binary tree. This is because the code uses a stack to store the recursive calls.