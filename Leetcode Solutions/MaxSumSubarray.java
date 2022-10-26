package com.arrays;

public class MaxSumSubarray {
    public static int maxSubArray(int[] nums) {
        if(nums.length==0 || nums==null) return 0;
        int sum=0, max=Integer.MIN_VALUE;

        for(int i=0; i<nums.length; i++){
            sum+= nums[i];
            max= Math.max(max,sum);
            sum= (sum<0)? 0: sum;
        }
        return max;
    }
}
