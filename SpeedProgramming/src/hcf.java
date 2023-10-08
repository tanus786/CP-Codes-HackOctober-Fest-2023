import java.util.Scanner;

public class hcf {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int num1 = sc.nextInt();
        System.out.print("Enter second number: ");
        int num2 = sc.nextInt();

        int result = hcf(num1, num2);
        System.out.println("HCF of " + num1 + " and " + num2 + " is: " + result);
    }

    public static int hcf(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        return hcf(num2, num1 % num2);
    }
}
