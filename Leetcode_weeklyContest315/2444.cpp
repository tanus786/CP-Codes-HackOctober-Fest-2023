/*2444. Count Subarrays With Fixed Bounds*/

/*You are given an integer array nums and two integers minK and maxK.
A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
    *The minimum value in the subarray is equal to minK.
    *The maximum value in the subarray is equal to maxK.

Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.*/

// Test cases
/*
1.)
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
2.)
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        vector<int> newvec;
        int size = nums.size();
        vector<int> v2;
        vector<int> v1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == minK)
                newvec.push_back(i);
        }
        newvec.push_back(size);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxK)
                v1.push_back(i);
        }
        v1.push_back(size);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
                v2.push_back(i);
        }
        v2.push_back(size);
        long long int ans = 0;
        for (int i = 0; i < size; i++)
        {
            int os2 = *lower_bound(newvec.begin(), newvec.end(), i);
            int os3 = *lower_bound(v1.begin(), v1.end(), i);
            int os1 = *lower_bound(v2.begin(), v2.end(), i);
            int ann = max(os2, os3);
            int temp = 0;
            if (ann < os1)
                temp = os1 - ann;

            ans += temp;
        }
        return ans;
    }
};