//3516. Find Closest Person
//LEETCODE PROBLEM DAILY


class Solution {
public:
    int findClosest(int x, int y, int z) {
        int subs1 = abs(z-x);
        int subs2 = abs(z-y);
        if(subs1<subs2){
        return 1;
        }
        if(subs1>subs2) {
        return 2;
        }
        return 0;
    }
