// euler's totient fnc
import java.util.Scanner;
class coprime {
    static int gcd(int x, int y)
    {
        if (x == 0)
            return y;
        return gcd(y % x, x);
    }
    public static void main(String[] args){
        int count = 1; // min val of euler_fnc
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for(int i=2; i < a; i++){
            if(gcd(i,a) == 1){
                count++;
            }
        }
        System.out.println(count);
    }
}
// time complexity - O(n*log(n))
// spance - O(n)
// Number of co-prime pairs from 1 to N (1,N; 2,N...) for a number N Φ(1) = 1 Φ(2) = 1 Φ(10) = 4
