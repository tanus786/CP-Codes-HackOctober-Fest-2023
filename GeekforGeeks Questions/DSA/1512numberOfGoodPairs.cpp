class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //sort the vector 
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            while(j<nums.size() && nums[i]==nums[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};