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
    void in(TreeNode* root,int& ans,int& k)
    {
        if(root==NULL)return;
        
        in(root->left,ans,k);
        
        if(k==1)ans=root->val;
        k--;
      
        in(root->right,ans,k);
    }
    
    public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        in(root,ans,k);
        return ans;
    }
};
