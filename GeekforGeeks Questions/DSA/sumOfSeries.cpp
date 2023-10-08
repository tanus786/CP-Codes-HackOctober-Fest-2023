class Solution{
public:
	// function to return sum of  1, 2, ... n
	long long seriesSum(int n) {
	    // code here
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
        }
        return sum;
	}
};