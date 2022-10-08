import java.util.Scanner;
public class Main {
    static void Binary(int arr[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                System.out.println("Element found at index:" + mid);
            if (arr[mid] > x)
                Binary(arr, l, mid - 1, x);
            Binary(arr, mid + 1, r, x);
        }
    }
    public static void main(String[] args) {
        int[] Arr = new int[20];
        int n;
        System.out.println("Enter number of Elements of an array\n");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        System.out.println("Enter Array Elements\n");
        for(int i=0;i<n;i++){
            Arr[i]=sc.nextInt();
        }
        System.out.println("Enter the number to be searched\n");
        int srch = sc.nextInt();
//      Binary search
        Binary(Arr,0,n-1,srch);
    }
}
