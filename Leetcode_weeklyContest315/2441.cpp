/*2441. Largest Positive Integer That Exists With Its Negative */

/*Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
Return the positive integer k. If there is no such integer, return -1.*/

// Test cases
/*
1.)
Input: nums = [-1,2,-3,3]
Output: 3
2.)
Input: nums = [-1,10,6,7,-7,1]
Output: 7
3.)
Input: nums = [-10,8,6,7,-2,-3]
Output: -1
*/

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        set<int> s;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (s.find(-1 * nums[i]) != s.end())
            {

                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};