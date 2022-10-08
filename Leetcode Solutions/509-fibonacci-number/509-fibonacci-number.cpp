class Solution {
public:
    int fib(int n) {
        if( n<= 0) return 0;
        if(n == 1 || n == 2) return 1; 
        int first = 1;
        int second = 1;
        while(n-- != 2){
            int temp = first+second;
            second = first;
            first = temp;
        }
        return first;
    }
};