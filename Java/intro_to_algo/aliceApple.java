import java.util.Scanner;
public class aliceApple {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter M");
        int M = sc.nextInt();
        System.out.println("Enter K");
        int K = sc.nextInt();
        System.out.println("Enter N");
        int N = sc.nextInt();
        System.out.println("Enter S");
        int S = sc.nextInt();
        System.out.println("Enter W");
        int W = sc.nextInt();
        System.out.println("Enter E");
        int E = sc.nextInt();

        System.out.print("Minimum value: ");
        if(M <= S*K){
            System.out.print(M);
        } else if (M <= S*K + E + W) {
            System.out.print((S * K) + (M - S * K) * K ); // (apples from South) + (remaining apples)*(number of apples per trees)
        }
        else {
            System.out.print(-1);
        }
    }
}
/* Concept
M: The number of red apples required.
K: The number of red apples each tree grows.
N: The number of trees in the North that do not have red apples.
S: The number of trees in the South that do not have green apples.
W: The number of trees in the West that have some red apples.
E: The number of trees in the East that have some green apples.

Check if M can be satisfied only from South direction, so output is minimum M.
If M can't be satisfied only from South, then we start looking in West & East and we use (S * K + E + W) apples.
If M still can't be satisfied then -1 because North does not have Red Apples. */
