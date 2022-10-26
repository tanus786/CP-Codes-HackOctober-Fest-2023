package com.hard;

import java.util.Arrays;

public class FindMissingPositive 
{
    public int firstMissingPositive(int[] nums) 
    {
    	 int min = 1, i=0;
         while(i<nums.length)
         {
             if(min==nums[i])
             {
                 min++;
                 i=0;
             }
             else
                 i++;
         }
         return min;
    }
}
