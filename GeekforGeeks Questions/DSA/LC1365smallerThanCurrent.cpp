class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            int count=0;
            for(auto j:nums){
                if(i>j)
                    count++;
            }   
            ans.push_back(count);

        }
        return ans;
    }
};