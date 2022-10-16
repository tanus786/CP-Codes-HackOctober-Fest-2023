#include <bits/stdc++.h>
using namespace std;

int robber(vector<int>& nums,int i,vector<int>&memo){
        if(i==0)return nums[0];
        if(i==1) return max(nums[0],nums[1]);
        if(memo[i]!=-1){
            return memo[i];
        }
        else{
         memo[i] = max(nums[i]+robber(nums,i-2,memo),robber(nums,i-1,memo));
        }
        return memo[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>memo(nums.size(),-1);
        return robber(nums,nums.size()-1,memo);
    }

