class Solution {
public:
    double myPow(double x, int n) {
        double temp;
        if(n == 0)
            return 1;
        if(n < 0){
            n = abs(n);
            x = 1/x;
        }
        temp = myPow(x, n/2);
            if(n%2==0){
                return temp * temp;
            }
        else{
            return x*temp*temp;
        }
    }
};
