Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Solution:

class Solution {
public:
    void helper(int idx, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        helper(idx+1, ds, ans, nums);
        ds.pop_back();
        helper(idx+1, ds, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0, ds, ans, nums);
        return ans;
    }
};
