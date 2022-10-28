package com.hard;

import java.util.Stack;

public class LargestRectangleInHistogram {
    public int largestRectangleArea(int[] heights) 
    {
    	if(heights==null || heights.length ==0)return 0;
    		
    	if(heights.length==1) return heights[0];
    	Stack<Integer> stack= new Stack<Integer>();
    	//We will keep pushing in the stack unless we find a value smaller 
    	//than the value at the top of stack
    	//If we find a smaller value, we will calculate our area, and keep updating it
    	int max=0;
    	//Adding the first index
    	stack.push(0);
    	for(int i=1; i<heights.length; i++)
    	{
    		int curr= heights[i];
    		if(curr >= heights[stack.peek()])
    		{
    			stack.push(i);
    		}
    		else
    		{
    			while(!stack.isEmpty() && curr < heights[stack.peek()])
    			{
    				int temp = heights[stack.pop()];
    				if(stack.isEmpty())
    				{
    					max=Math.max(max, temp*i);
    				}
    				else
    				{
    					max=Math.max(max, temp*(i-stack.peek()-1));
    				}
    			}
    			stack.add(i);
    		}
    	}
    	//If the array is increasing
    	if(!stack.isEmpty())
    	{
    		int i=heights.length;
    		while(!stack.isEmpty())
			{
				int temp = heights[stack.pop()];
				if(stack.isEmpty())
				{
					max=Math.max(max, temp*i);
				}
				else
				{
					max=Math.max(max, temp*(i-stack.peek()-1));
				}
			}
    	}
    	return max;
    }
}
