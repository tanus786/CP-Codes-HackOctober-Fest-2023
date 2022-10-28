class Solution { 
     public int maxSubArray(int[] nums) { 
         int MaxEnd = 0; 
         int maxSum = nums[0]; 
  
         for(int i=0; i<nums.length; i++) { 
             MaxEnd = MaxEnd+nums[i]; 
             if(MaxEnd > maxSum) { 
                 maxSum = MaxEnd; 
             } 
             if(MaxEnd < 0) { 
                 MaxEnd = 0; 
             } 
         } 
         return maxSum; 
     } 
 }
