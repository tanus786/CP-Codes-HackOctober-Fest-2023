import java.util.Scanner;
class Prime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        boolean[] arr = new boolean[a + 1];

        for (int i = 2; i * i <= a; i++) {
            if (!arr[i]) {
                for (int j = i + 1; j <= a; j = j + i) {
                    arr[j] = true;
                }
            }
        }

        for (int i = 2; i <= a; i++) {
            if (arr[i]) {
                System.out.println(i);
            }
        }
    }
}
// Time complexity - O(log(log n))
// Space Complexity - O(n)
