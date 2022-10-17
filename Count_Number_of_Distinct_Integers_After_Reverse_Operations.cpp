// Problem statement
// Leetocde contest october 16 question
// level-medium
// You are given an array nums consisting of positive integers.

// You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.

// Return the number of distinct integers in the final array.
  
//   Example 1:

// Input: nums = [1,13,10,12,31]
// Output: 6
// Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
// The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
// The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).


class Solution {
public:
    int reverse(int n){
        int sum=0;
        while(n!=0){
            sum=sum*10+n%10;
            n/=10;
        }
        return sum;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0; i<n; i++){ 
           int ans=reverse(nums[i]);
          nums.push_back(ans);
         
        }
        int cnt=1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
           // cout<<nums[i];
            if(nums[i]!=nums[i-1]){
                
                cnt++;
            }
           
        }
        return cnt;
    }
};

 
