import java.util.Scanner;

public class insertion_sort {
    public static void insertionSort(int n, int[] arr) {
        for (int i = 1; i < n; ++i) {
            int curr = arr[i];
            int idx = i - 1;

            while (idx >= 0 && arr[idx] > curr) {
                arr[idx + 1] = arr[idx];
                --idx;
            }

            arr[idx + 1] = curr;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        int n = scanner.nextInt();
        int[] arr = new int[n];

        
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

       

        insertionSort(n, arr);

        
        for (int num : arr) {
            System.out.print(num + " ");
        }

        scanner.close();
    }
}
