#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       vector<int> ans;
       vector<int> leftSum={0};
         vector<int> rightSum={0};
        for(int i=0;i<nums.size();i++){
            leftSum.push_back(leftSum[i]);
            rightSum.push_back(rightSum[nums.size()-i-1]);
            ans.push_back(rightSum[nums.size()-i-1]-leftSum[i]);

        }
        return ans;
    }
};