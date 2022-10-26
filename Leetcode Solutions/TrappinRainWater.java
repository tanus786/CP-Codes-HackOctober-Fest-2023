package com.hard;

public class TrappinRainWater {
    public int trap(int[] height) 
    {
    	if(height.length<=0 || height==null)
    		return 0;
    	int[] leftMax= new int[height.length];
    	int[] rightMax= new int[height.length];
    	
    	leftMax[0]= height[0];
    	rightMax[height.length-1]= height[height.length-1];
    	
    	for(int i=1; i<height.length; i++)
    		leftMax[i]= Math.max(leftMax[i-1], height[i]);
    	
    	for(int i= height.length-2; i>=0; i--)
    		rightMax[i]= Math.max(rightMax[i+1], height[i]);
    	
    	int value=0;
    	
    	for(int i=0; i<height.length; i++)
    		if(Math.min(leftMax[i],rightMax[i])- height[i] >0)
    			value+= Math.min(leftMax[i],rightMax[i])- height[i];
    	
    	return value;
    }
}
