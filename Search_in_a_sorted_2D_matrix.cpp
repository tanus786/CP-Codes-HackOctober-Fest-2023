// Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

// Given matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

// Example 1:

// Input: matrix = 
// [[1,3,5,7],
//  [10,11,16,20],
//  [23,30,34,60]], 

// target = 3

// Output: true

// Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.
// Example 2:

// Input: matrix = 
// [[1,3,5,7],
//  [10,11,16,20],
//  [23,30,34,60]], 

// target = 13

// Output: false

// Explanation: As the given integer(target) does not exist in the given 2D matrix, the function has returned false.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
