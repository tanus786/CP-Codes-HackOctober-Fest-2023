import java.util.Arrays;
import java.util.Scanner;

class bulbToggle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // number of rounds
        int m = sc.nextInt(); // number of bulbs

        boolean[] bulbs = new boolean[m];

        // increment n times starting from 1
        for (int i = 1; i <= n; i++) {
            // start from index 0; increment each j until m
            for (int j = i - 1; j < m; j += i) {
                bulbs[j] = !bulbs[j];
            }
            System.out.println("Bulbs state after iteration " + i + ": " + Arrays.toString(bulbs));
        }

        // count ON bulbs
        int count = 0;
        for (boolean bulbState : bulbs) {
            if (bulbState) {
                count++; // increment on each true
            }
        }

        System.out.println("Number of bulbs ON at the end: " + count);
    }
}
