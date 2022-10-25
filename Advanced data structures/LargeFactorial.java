import java.math.BigInteger;
import java.util.ArrayList;

class LargeFactorial{
    public static void calculateFactorial(int N) {
         BigInteger result = BigInteger.ONE;
         for(int i=1;i<=N;i++){
            result = result.multiply(BigInteger.valueOf(i));
         }
       System.out.println("Factorial of "+ N +"is"+ result);
    }

    static void gcd1(int n1 ,int n2){
        BigInteger no1 =BigInteger.valueOf(n1);
        BigInteger result = no1.gcd(BigInteger.valueOf(n2));
        System.out.println("Gcd of number "+ result);
    }

    static void divAndRem(int n1 ,int n2){
        BigInteger no1 =BigInteger.valueOf(n1);
        BigInteger result[] = no1.divideAndRemainder(BigInteger.valueOf(n2));
        System.out.println("quotient of numbers "+ result[0]);
        System.out.println("remainder of numbers "+ result[1]);
    }
    public static void main(String []args){
      calculateFactorial(1000);
      gcd1(20,10);
      divAndRem(50000, 76);
    }
}