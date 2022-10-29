/*2442. Count Number of Distinct Integers After Reverse Operations*/

/*You are given an array nums consisting of positive integers.
You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
Return the number of distinct integers in the final array.*/

// Test cases
/*
1.)
Input: nums = [1,13,10,12,31]
Output: 6
2.)
Input: nums = [2,2,2]
Output: 1
*/

class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            int d = nums[i];
            while (d != 0)
            {
                int l = d % 10;
                c = c * 10 + l;
                d /= 10;
            }
            s.insert(c);
        }
        return s.size();
    }
};