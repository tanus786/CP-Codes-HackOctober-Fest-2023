// * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// PROBLEM STATEMENT :  Given the root of a binary tree and an integer targetSum, return true if the tree 
// has a root-to-leaf path such that adding up all the values along the path equals targetSum.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
      // calculating the the current value to be searched
        int curSum=targetSum-root->val;
        bool ans=0;
      // found condition when sum is found and reached leaf node
        if(curSum==0 && root->left==NULL & root->right==NULL)
            return true;
        //if left and right node not null keep on searching 
        if(root->left!=NULL)
            ans=ans||hasPathSum(root->left,curSum);
        if(root->right!=NULL)
            ans=ans||hasPathSum(root->right,curSum);
        
        return ans;

    }
        
};
