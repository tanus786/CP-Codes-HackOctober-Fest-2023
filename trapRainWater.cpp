// Trapping Rainwater Problem in Arrays
// Given n non - negative integers representing an elevation map where the width of each bar is 1,
// We need to compute how much water it can trap after raining.
// Input : height = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ]
// Output : 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
// In this case, 6 units of rain water (blue section) are being trapped.
// #LeetCode Hard Question
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity : O(N^2)
// Space Complexity : O(1)
int trapBrute(vector<int> &height)
{
    int n = height.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // Calculating left max and right max till that point each time
        // Hence greater complexity
        int lmax = height[i], rmax = height[i];
        if (i > 0)
        {
            for (int j = 0; j <= i; j++)
            {
                lmax = max(lmax, height[j]);
            }
        }
        if (i < n)
        {
            for (int j = i; j < n; j++)
            {
                rmax = max(rmax, height[j]);
            }
        }
        // Adding up unit water to result
        res += min(lmax, rmax) - height[i];
    }
    return res;
}

// Better Approach Using Prefix and Suffix Sum
// Time Complexity : O(N) + O(N) + O(N) = O(N)
// Space Complexity : O(N) + O(N) = O(2N) [due to 2 extra arrays usage]
int trapBetter(vector<int> &height)
{
    int n = height.size();
    int res = 0;
    // Using prefix and suffix arrays to compute left and right maximum till that extent
    vector<int> pre(n);
    vector<int> suf(n);
    pre[0] = height[0];
    suf[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
        pre[i] = max(height[i], pre[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(height[i], suf[i + 1]);

    for (int i = 0; i < n; i++)
    {
        // Calculating result
        res += min(pre[i], suf[i]) - height[i];
    }
    return res;
}

// Optimized Approach
// Time Complexity : O(N) [Two pointer approach]
// Space Complexity : O(1)
int trapOpt(vector<int> &height)
{
    // Calculating size of height vector
    int n = height.size();
    int l = 0, r = n - 1, lmax = 0, rmax = 0, res = 0;
    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            // if height on left is greater than max height
            if (height[l] >= lmax)
                lmax = height[l];
            else
                // adding unit water to result
                res += lmax - height[l];
            l++;
        }
        else
        {
            // checking for right maximum and adding unit water
            if (height[r] >= rmax)
                rmax = height[r];
            else
                res += rmax - height[r];
            r--;
        }
    }
    return res;
}

// Main Function
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    // Input for height array
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Printing Result
    cout << trapOpt(arr) << endl;
    return 0;
}