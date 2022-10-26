package com.arrays;

public class TrailingZeroesFactorial {
    public int trailingZeroes(int n) {
        int count=0;
        while(n>=5){
            count+= (int)Math.floor(n/5);
            n=(int)Math.floor(n/5);
        }
        return count;
    }
}
