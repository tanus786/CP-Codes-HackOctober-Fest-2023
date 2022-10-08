/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool Helperfn(TreeNode* leftRoot,TreeNode* rightRoot){
        if(!leftRoot || !rightRoot) return leftRoot == rightRoot;
        
        if(leftRoot->val != rightRoot->val) return false;
        
        return Helperfn(leftRoot->left,rightRoot->right) && Helperfn(leftRoot->right,rightRoot->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return !root || Helperfn(root->left,root->right);
    }
};