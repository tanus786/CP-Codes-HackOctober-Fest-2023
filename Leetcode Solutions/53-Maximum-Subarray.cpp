class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size() ;
        int currentMax = INT_MIN, tempMax = 0;
        
        for (int i = 0; i < n; i++)
        {
            tempMax = tempMax + nums[i];
            if (currentMax < tempMax)
                currentMax = tempMax;
            if (tempMax < 0)  
                tempMax = 0;
        }
        return currentMax;
    }
};
