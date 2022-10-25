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
public:
    bool isBalanced(TreeNode* root) {
         if(height(root)!=-1)return true;
         return false;
    }

    int height(TreeNode* root){
        if(root==NULL)return 0;
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l-r)>1 || l==-1 || r==-1)return -1;
        return max(height(root->left),height(root->right))+1;
    }

};