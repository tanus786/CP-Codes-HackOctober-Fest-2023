package com.arrays;

import java.util.HashMap;
import java.util.Scanner;

public class TwoSum 
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int[] nums=new int[] {2,5,7,9};
		int sum=9;
		System.out.println(twoSum(nums, sum));
		
	}

	private static int[] twoSum(int[] numbers, int target)
	{
		int[] sol=new int[2];
		HashMap<Integer, Integer> h=new HashMap<Integer, Integer>();
		for(int i=0; i<numbers.length; i++)
		{
			Integer diff = (Integer)(target - numbers[i]);
            if(h.containsKey(diff))
            {
                int toReturn[] = {h.get(diff), i};
                System.out.println(toReturn);
                return toReturn;
            }
            h.put(numbers[i],i);
		}
		return null;
	}
}
