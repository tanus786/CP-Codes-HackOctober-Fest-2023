#include <bits/stdc++.h>
using namespace std;
int houseRobber(vector<int>&nums){
        int dp[nums.size()+1];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[1],nums[0]);
          // either use first house and can't use last or last and not first:Circular or
         vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
         return max(houseRobber(v1), houseRobber(v2));
    }

    int main(){
        ll n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        cout<<rob(v)<<endl;
        return 0;
    }

    //Time complexity :O(N)
    //Space complexity : O(N) we are using extra auxilary array for this(Memoization part in DP)