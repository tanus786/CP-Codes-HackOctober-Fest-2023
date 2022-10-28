package com.hard;

public class SubarraySumAtleastK {
    public int shortestSubarray(int[] A, int K) {
        if(A.length <=0 || A==null)
        	return -1;
        int sumAll=0;
        for(int i=0; i<A.length; i++)
        	if(A[i]>0)
        		sumAll += A[i];
        if(sumAll <K)
        	return -1;
        int currsum=0, minLen= A.length+1;
        int start=0, end=0;
        
        while(end< A.length)
        {
        	while(currsum<K && end<A.length)
        		currsum+=A[end++];
        	
        	while(currsum>=K && start<A.length)
        	{
        		if(end-start< minLen)
        			minLen= (end- start);
        		currsum-=A[start++];	//removing values in front
        	}
        }
        return minLen;
    }
}
