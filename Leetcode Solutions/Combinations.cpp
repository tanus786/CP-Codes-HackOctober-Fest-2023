Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Solution:

class Solution {
public:
    void helper(int i, vector<int> &ds, vector<vector<int>> &ans, int n, int k){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i==n+1){
            return;
        }
        ds.push_back(i);
        helper(i+1, ds, ans, n, k);
        ds.pop_back();
        helper(i+1, ds, ans, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(1, ds, ans, n, k);
        return ans;
    }
};
