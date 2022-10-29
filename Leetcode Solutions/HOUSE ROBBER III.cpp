/* Author :  JaiSehgal007 */

/* House Robber Problem III from Leetcode */

/* Link to the Problem : https://leetcode.com/problems/house-robber-iii/ */

/*
PROBLEM DESCRIPTION:
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will 
automatically contact the police if two directly-linked houses were broken into on the same night.
Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

/*
EXAMPLES TO THE PROBLEM:
Example 1:
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/*-------------------------------------SOLUTION---------------------------------------*/
class Solution {
public:
    int robber(TreeNode* root,int &l,int &r){
        if(!root)return 0;
        int ll=0,lr=0,rl=0,rr=0;
        l=robber(root->left,ll,lr);
        r=robber(root->right,rl,rr);

        return max(l+r,root->val+ll+lr+rl+rr);

    }
    int rob(TreeNode* root) {
        int l,r;
        return robber(root,l,r);
    }
};
