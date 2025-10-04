class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
                int j=i+1,k=n-1;
            while(j<n && j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(k-1>0 && nums[k]==nums[k-1])k--;
                    while(j+1<n && nums[j]==nums[j+1])j++;
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>-nums[i]){
                     while(k-1>0 && nums[k]==nums[k-1])k--;
                     k--;
                }
                else{
                    while(j+1<n && nums[j]==nums[j+1])j++; 
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
       return ans; 
    }
    
};
