package com.arrays;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RangeSumOfSortedSubarray {
    public static int rangeSum(int[] nums, int n, int left, int right)
    {
            int MOD = 1000000007;
            List<Integer> ls = new ArrayList<>();
            int res = 0;
            for (int i = 0; i < n; i++) {
                int sum = nums[i];
                ls.add(sum);
                for (int j = i + 1; j < n; j++) {
                    sum += nums[j];
                    ls.add(sum);
                }
            }
            Collections.sort(ls);
            for (int i = left - 1; i < right; i++) {
                res = (res % MOD + ls.get(i) % MOD);
            }
            return res;
       
    }
    public static void main(String[] args) {
		int nums[]= {1,2,3,4};
		int n=4;
		int left= 1, right=5;
		System.out.println(rangeSum(nums, n, left, right));
	}
}
