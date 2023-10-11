// Question link:-  https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;

        }
        int max=INT_MAX,f=nums.size()/2;
        for(auto it:umap){
            if(it.second>f)
                max=it.first;
        }

        return max;
    }
};
