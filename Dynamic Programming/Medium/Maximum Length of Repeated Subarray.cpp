


#include <bits/stdc++.h>
using namespace std;



int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[nums1.size()+1][nums2.size()+1];
        for(int i=0;i<nums1.size()+1;i++){
            for(int j=0;j<nums2.size()+1;j++){
                dp[i][j] = 0;
            }
        }
        int res = 0;
        for(int i=1;i<nums1.size()+1;i++){
            for(int j=1;j<nums2.size()+1;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }