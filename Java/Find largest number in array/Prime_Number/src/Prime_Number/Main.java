package Prime_Number;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
	// Find a number prime or not
        Scanner input = new Scanner(System.in);
        int n, i, v=0 ;
        System.out.println("Enter a positive number ");
        n= input.nextInt();
        if ( n==1 || n==0){
            System.out.println(n+" is not a prime number. ");
        }
        else {
            for (i=2;i<=n/2;i++){
                if(n%i==0){
                    v=1;
                    break;
                }

            }
           if ( v==1){
               System.out.println(n+" is not a prime number ");
           }
           else {
               System.out.println(n+" is a prime number ");
           }
        }
    }
}
