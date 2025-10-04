/*
Longest subset zero sum
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.

Constraints:
0 <= N <= 10^8

Time Limit: 1 sec

Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5

Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
*/

#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> prefixSum;
    
    int maxLength = 0;
	int runningSum = 0;    
    for(int i = 0; i < n; i++) {
        runningSum += arr[i];
         
        // Corner cases
        if (arr[i] == 0 and maxLength == 0) {
            maxLength = 1;
        }
        if (runningSum == 0) { // if Sum upto index i is 0 then whatever is the length will be samller than i + 1, hence length is updated
            maxLength = i + 1;
        }
        
        if(prefixSum.find(runningSum) != prefixSum.end()) {
            maxLength = max(maxLength, i - prefixSum[runningSum]);
        } else {
            prefixSum[runningSum] = i;
        }
    }
    
    return maxLength;
}

// Time Complexiity : O(n)
// Auxillary Space : O(n)
