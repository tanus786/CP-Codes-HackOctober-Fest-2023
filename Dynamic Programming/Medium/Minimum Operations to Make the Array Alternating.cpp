#include <bits/stdc++.h>
using namespace std;


int dp[100005][2];
    int minimumOperations(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        int n=nums.size(), i, j, k, ans=0;
        for(i = 0; i < n; i++) {
			dp[nums[i]][i&1]++;
		}
        for(i = 1, j=k=0; i <= 100000; i++) {
		   // Add the maximum frequency of odd indexes to maximum frequency even indexes 
		   //and vice versa, it will give us how many elements we don't need to change. 
            ans = max(ans, max(dp[i][0] + k, dp[i][1] + j));
            j = max(j, dp[i][0]);
            k = max(k, dp[i][1]);
        }
        return n - ans;
    }