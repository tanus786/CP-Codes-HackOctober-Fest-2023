class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = INT_MAX;
        int difference = INT_MAX;
        for(int index = 0; index < nums.size()-2; index++)
        {
            if (index == 0 || nums[index - 1] != nums[index]) 
            {
                generateSumValues(index, target, sum, difference, nums);   
                if(sum == target)
                    return sum;
            }
        }
        return sum;
    }
    
    void generateSumValues(int index, int target, int& sum, int& difference, const vector<int>& nums)
    {
        int low = index+1, hi = nums.size()-1;
        while(low < hi)
        {
            int tempSum = nums[index] + nums[low] + nums[hi];
            int tempDifference = target - tempSum;
            int absDifference = abs(tempDifference);
            if(absDifference < difference)
            {
                difference = absDifference;
                sum = tempSum;
            }
            if(tempSum < target)
                low++;
            else if(tempSum > target)
                hi--;
            else return;
        }
    }
};
