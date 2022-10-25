package com.hard;

import java.util.HashSet;

public class LongestConsequentSubseq {
    public int longestConsecutive(int[] nums) 
    {
    	int n= nums.length;
    	int ans=0;
    	HashSet<Integer> h= new HashSet<Integer>();
    	for(int i=0; i<nums.length; i++)
    		h.add(nums[i]);
    	
    	for(int i=0; i<nums.length; i++)
    	{
    		if(!h.contains(nums[i]-1)) //checking if this is current ele
    		{
    			int j=nums[i];
    			while(h.contains(j)) j++;
    			if(ans<j-nums[i])
    				ans=j-nums[i];
    		}
    	}
    	return ans;
    }
}
