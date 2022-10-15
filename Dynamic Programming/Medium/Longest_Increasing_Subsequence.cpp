// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int result = 1;
    int n = nums.size();
    vector<int> t(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                t[i] = max(t[i], t[j] + 1);
            }
            result = max(result, t[i]);
        }
    }
    return result;
}

int main()
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    cout << lengthOfLIS(nums);
}