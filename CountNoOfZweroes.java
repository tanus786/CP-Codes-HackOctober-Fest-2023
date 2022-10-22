package com.company.Property;

public class CountNoOfZweroes {
    public static void main(String[] args) {
        int n=3000210;
        noOfzero(n);
        System.out.println(count);
        System.out.println(NOOFZERO(n,0));
    }

    private static int NOOFZERO(int n,int count) {
        if(n<=0){
            return count;
        }
        int k=n%10;
        if(k==0){
            return NOOFZERO(n/10,count+1);
        }
        else {
           return  NOOFZERO(n/10,count);
        }
    }

    static int count=0;
    private static void noOfzero(int n){

        if(n==0){
            return;
        }
        if (n%10==0){
            count++;
        }
        noOfzero(n/10);


    }
}
