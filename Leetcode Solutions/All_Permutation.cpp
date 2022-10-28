
// Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Here above all permutations of the nums array is printed.
//Problem Link:- https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n;
        n=nums.size();
        	vector<vector <int> > ans;

        permutation(0,n,nums,ans);
        
        return ans;
        
    }
  
    void permutation(int i,int n,vector <int> &  nums,vector<vector <int> > &ans)
    {

      //Base condition. If end of array reached, return it.
      if(i==n)
      {
        ans.push_back(nums);
            return;
      }

      for(int j=i;j<n;j++)
      {
        swap(nums[i],nums[j]);// Swap elements for different permutations
        permutation(i+1,n,nums,ans);// See all permuataions after swapping the array.
        swap(nums[i],nums[j]);// Re-swap for original array.
      }

    }

};