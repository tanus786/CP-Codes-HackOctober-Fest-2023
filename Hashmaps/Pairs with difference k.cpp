/*
Pairs with difference K
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.

Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 

Constraints :
0 <= n <= 10^4

Time Limit: 1 sec

Sample Input 1 :
4 
5 1 2 4
3

Sample Output 1 :
2


Sample Input 2 :
4
4 4 4 4 
0

Sample Output 2 :
6
*/

#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    
    unordered_map<int,int> frequency;
    
    for(int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    
    int count = 0;
    
    // corner case
    if(k == 0) {
        for(auto itr : frequency) {
            if(itr.second >= 2){
                count += ((itr.second) * (itr.second - 1) ) / 2;   // n choose 2
            }
        }
    } else { // Standard Case 
    	for(auto itr : frequency) {
        	if(frequency.find(itr.first - k) != frequency.end()) {
            	count += itr.second * frequency[itr.first - k];
        	}
        
        	if(frequency.find(itr.first + k) != frequency.end()) {
            	count += itr.second * frequency[itr.first + k];
        	} 	
        
        	frequency[itr.first] = 0;
    	}
    }  
    
    return count;
}

// Time Complexity : O(n)
// Auxillary Space :: O(n)
