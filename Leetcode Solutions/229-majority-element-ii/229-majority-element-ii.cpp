class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int nums1 = INT_MAX, nums2 = INT_MAX, count1 = 0, count2 = 0;
        for(auto i : nums){
            if(i == nums1) count1++;
            else if(i == nums2) count2++;
            else if(count1 == 0){
                nums1 = i;
                count1 = 1;
            }else if(count2 == 0){
                nums2 = i;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        //validating answer
        vector<int> ans;
        count1 = count2 = 0;
        for(auto i : nums){
            if(nums1 == i) count1++;
            if(nums2 == i) count2++;
        }
        if(count1 > sz/3) ans.push_back(nums1);
        if(count2 > sz/3) ans.push_back(nums2);
        
        return ans;
    }
};