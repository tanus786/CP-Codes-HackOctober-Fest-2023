Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Solution:

class Solution {
public:
    void helper(int i, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        if(ds.size()==i || nums[i]!=nums[i-1]){
            ds.push_back(nums[i]);
            helper(i+1, ds, ans, nums);
            ds.pop_back();
        }
        helper(i+1, ds, ans, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0, ds, ans, nums);
        return ans;
    }
};
